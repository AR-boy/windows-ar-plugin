#pragma
#include "detect_markers.h";
#include "utilities.h"

/**
 *
 * Analyses the frame detecting aruco markers, markerIds 
 * and rejectedCandidateMarkers
 *
 * @param 4 channel(BGRA) ubyte buffer representing an image, containing 0-255 for each pixel
 * @param value for number of pixels in x axis
 * @param value for number of pixels in y axis
 * @param out parameter, a list of unique identifiers for each marker
 * @param out parameter, a list of markers and their corner locations
 * @param out parameter, a list of rejectedMarkers and their corner locations
*/
void DetectMarkers(
	unsigned char* textureData,
	int width,
	int height,
	std::vector<int> * markerIds,
	std::vector<std::vector<cv::Point2f>> * markers,
	std::vector<std::vector<cv::Point2f>> * rejectedMarkers
)
{
	try
	{
		// format ubyte buffer to gray frame
		cv::Mat greyTexture = ConvertUnityTextureToMat(textureData, width, height);
		// create default detection parameters for aruco marker detection
		cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
		// set tp use corner refinement for accuracy, values obtained 
		// for pixel coordinates are more accurate than the neaterst pixel 
		parameters->cornerRefinementMethod = cv::aruco::CORNER_REFINE_SUBPIX;
		// create a dictionary
		cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
		// run detectMarkers
		cv::aruco::detectMarkers(greyTexture, dictionary, *markers, *markerIds, parameters, *rejectedMarkers);
	}
	catch (cv::Exception& e)
	{
		std::cerr << e.msg << std::endl;
	}
}