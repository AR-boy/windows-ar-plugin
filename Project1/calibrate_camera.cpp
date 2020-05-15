#pragma
#include "calibrate_camera.h";
#include "utilities.h"
#include <windows.h>


/**
 *
 * Detects charuco board in the frame
 *
 * @param 4 channel(BGRA) ubyte buffer representing an image, containing 0-255 for each pixel.
 * @param value for number of pixels in x axis
 * @param value for number of pixels in y axis
 * @param the number of vertical squares
 * @param the number of horizontal squares
 * @param the size of a square in cm
 * @param the size of a marker in cm
 * @param out parameter, returns true if board is found
 * @param inOut parameter, a list of unique identifiers for charuco corners found
 * @param inOut parameter, a list of corners
*/

void DetectCharucoBoard(
	unsigned char* textureData,
	int width,
	int height,
	int squaresW,
	int squaresH,
	float squareLength,
	float markerLength,
	bool* boarDetected,
	std::vector<std::vector<int>>* allCharucoIds,
	std::vector<std::vector<cv::Point2f>>* allCharucoCorners
)
{
	try
	{
		// format ubyte buffer to cv::Mat
		cv::Mat greyTexture = ConvertUnityTextureToMat(textureData, width, height);

		// create dictionary
		cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
		// create a charuco board with specified dimensions
		cv::Ptr<cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(squaresW, squaresH, squareLength, markerLength, dictionary);

		// set up containers
		std::vector<int> markerIds;
		std::vector<std::vector<cv::Point2f>> markerCorners;
		std::vector<std::vector<cv::Point2f>> rejectedMarkers;
		// create default detection parameters for aruco marker detection
		cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
		// set tp use corner refinement for accuracy, values obtained 
		// for pixel coordinates are more accurate than the neaterst pixel 
		parameters->cornerRefinementMethod = cv::aruco::CORNER_REFINE_SUBPIX;
		// run detectMarkers
		cv::aruco::detectMarkers(greyTexture, dictionary, markerCorners, markerIds, parameters, rejectedMarkers);
		// set up containers
		std::vector<int> charucoIds;
		std::vector<cv::Point2f> charucoCorners;

		// only run if markers are found
		if (markerIds.size() > 0)
		{
			cv::aruco::interpolateCornersCharuco(markerCorners, markerIds, greyTexture, board, charucoCorners, charucoIds);
			allCharucoCorners->push_back(charucoCorners);
			allCharucoIds->push_back(charucoIds);

			*boarDetected = true;
		}
		else
		{
			*boarDetected = false;
		}
	}
	catch (cv::Exception& e)
	{
		std::cerr << e.msg << std::endl;
	}

}

/**
 *
 * Uses previously collected data, to calibrate camera and return camera calibration parameters
 *
 * @param 4 channel(BGRA) ubyte buffer representing an image, containing 0-255 for each pixel.
 * @param value for number of pixels in x axis
 * @param value for number of pixels in y axis
 * @param the number of vertical squares
 * @param the number of horizontal squares
 * @param the size of a square in cm
 * @param the size of a marker in cm
 * @param out parameter, returns true if board is found
 * @param in parameter, a list of unique identifiers for charuco corners found
 * @param in parameter, a list of corners
 * @param out parameter, a matrix of cameraMatrix values
 * @param out parameter, a matrix of distCoeffs values
*/


double CalibrateCameraCharuco(
	int height,
	int width,
	int squaresW,
	int squaresH,
	float squareLength,
	float markersLength,
	std::vector<std::vector<int>>* allCharucoIds,
	std::vector<std::vector<cv::Point2f>>* allCharucoCorners,
	cv::Mat* cameraMatrix,
	cv::Mat* distCoeffs
)
{
	try {

		// set up containers
		std::vector<cv::Mat> rvecs;
		std::vector<cv::Mat> tvecs;

		cv::Size imgSize = cv::Size(height, width);

		// intialise camera calibration data containers
		*cameraMatrix = cv::Mat(3, 3, CV_64F);
		cameraMatrix->ptr<double>(0)[0] = 1;
		cameraMatrix->ptr<double>(1)[1] = 1;

		*distCoeffs = cv::Mat::zeros(1, 14, CV_64F);

		// get chosen dictionary
		cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
		// create charuco board with obtained params
		cv::Ptr<cv::aruco::CharucoBoard> board = cv::aruco::CharucoBoard::create(squaresW, squaresH, squareLength, markersLength, dictionary);
		// set optimisation flags
		int calibrationFlags = (cv::CALIB_RATIONAL_MODEL + cv::CALIB_FIX_ASPECT_RATIO);
		// calibrates camera
		return cv::aruco::calibrateCameraCharuco(*allCharucoCorners, *allCharucoIds, board, imgSize, *cameraMatrix, *distCoeffs, rvecs, tvecs, calibrationFlags);
	}
	catch (cv::Exception& e)
	{
		std::cerr << e.msg << std::endl;
	}
}