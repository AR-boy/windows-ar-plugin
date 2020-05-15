#pragma
#include "estimate_pose.h";
#include "utilities.h";
#include "calibrate_camera.h";
#include <windows.h>
#include <string> 
#include <stdio.h>
#include <iostream>


/**
 *
 * Analyses the frame estimating pose from recieved camera parameters 
 * and charuco corners in the frame
 *
 * @param 4 channel(BGRA) ubyte buffer representing an image, containing 0-255 for each pixel.
 * @param value for number of pixels in x axis
 * @param value for number of pixels in y axis
 * @param the size of a marker in cm
 * @param the size of a square in cm
 * @param out parameter, a list of unique identifiers for each marker
 * @param out parameter, a list of markers and their corner locations
 * @param out parameter, a list of rejectedMarkers and their corner locations
 * @param in parameter, a matrix of cameraMatrix values
 * @param in parameter, a matrix of distCoeffs values
 * @param out parameter, a vector of rvec values
 * @param out parameter, a vector of tvec values
 * @param out parameter, a matrix of eulerRvecs values
*/
void EstimateCharucoBoardPose(
	unsigned char* textureData,
	int width,
	int height,
	float markerLength,
	float squareLength,
	int markersX,
	int markersY,
	std::vector<int>* markerIds,
	std::vector<std::vector<cv::Point2f>>* markerCorners,
	std::vector<std::vector<cv::Point2f>>* rejectedCandidates,
	cv::Mat* cameraMatrix,
	cv::Mat* distCoeffs,
	cv::Vec3d* rvec,
	cv::Vec3d* tvec,
	cv::Mat* eulerRvecs
)
{
	try
	{
		// format ubyte buffer to gray frame
		cv::Mat greyTexture = ConvertUnityTextureToMat(textureData, width, height);
		// get chosen dictionary
		cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
		// create charuco board with obtained params
		cv::Ptr<cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(markersX, markersY, squareLength, markerLength, dictionary);
		// create default detection parameters for aruco marker detection
		cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
		// set tp use corner refinement for accuracy, values obtained 
		// for pixel coordinates are more accurate than the neaterst pixel 
		parameters->cornerRefinementMethod = cv::aruco::CORNER_REFINE_SUBPIX;
		// run detectMarkers
		cv::aruco::detectMarkers(greyTexture, dictionary, *markerCorners, *markerIds, parameters, *rejectedCandidates);

		// set up ids and corner containers
		std::vector<int> charucoIds;
		std::vector<cv::Point2f> charucoCorners;

		// only run if markers are found
		if (markerIds->size() > 0)
		{
			// find charuco corners
			cv::aruco::interpolateCornersCharuco(*markerCorners, *markerIds, greyTexture, board, charucoCorners, charucoIds);
		}
		// only run if charuco corners are found
		if (charucoIds.size() > 0)
		{
			// gets pose
			cv::aruco::estimatePoseCharucoBoard(charucoCorners, charucoIds, board, *cameraMatrix, *distCoeffs, *rvec, *tvec, false);
		}
		// transform to Euler Angles
		RotationVectorToEulerAngles(rvec, eulerRvecs);
	}
	catch (cv::Exception& e)
	{
		OutputDebugString(e.msg.c_str());
	}
}