#pragma once
#include "utilities.h"


/**
 *
 * converts the frame to grayscale
 * and rejectedCandidateMarkers
 *
 * @param 4 channel(BGRA) ubyte buffer representing an image, containing 0-255 for each pixel
 * @param value for number of pixels in x axis
 * @param value for number of pixels in y axis
 * @return a grayscale cv::Mat formatted frame
*/
cv::Mat ConvertUnityTextureToMat(
	unsigned char* textureData,
	int width,
	int height
)
{
	// format buffer to cv::Mat
	cv::Mat texture = cv::Mat(height, width, CV_8UC4, textureData);
	// set up single chanel grayscale cv::Mat
	cv::Mat grayTexture = cv::Mat(height, width, CV_8U);
	// colour to grayscale 
	cv::cvtColor(texture, grayTexture, cv::COLOR_BGRA2GRAY);
	// flip imaage to match untiy coordinate format 
	cv::flip(grayTexture, grayTexture, 0);
	// return image
	return grayTexture;

}


/**
 *
 * converts rotation vectors into Euler angles using method specified
 * in the following paper - https://www.gregslabaugh.net/publications/euler.pdf
 *
 * @param in parameter, a pointer to rotation vector
 * @param out parameter, a pointer to euler angles in memory
*/
void RotationVectorToEulerAngles(
	cv::Vec3d* rvec,
	cv::Mat* eulerRvecs
)
{

	cv::Mat rotationMatrix;
	cv::Rodrigues(*rvec, rotationMatrix);

	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	if (rotationMatrix.at<double>(2, 0) != -1.0 && rotationMatrix.at<double>(2, 0) != 1.0)
	{
		x = -asin(rotationMatrix.at<double>(2, 0));
		z = atan2((rotationMatrix.at<double>(2, 1) / cos(x)), (rotationMatrix.at<double>(2, 2) / cos(x)));
		y = atan2((rotationMatrix.at<double>(1, 0) / cos(x)), (rotationMatrix.at<double>(0, 0) / cos(x)));
	}
	else
	{
		y = 0.0;
		if (rotationMatrix.at<double>(2, 0) == -1)
		{
			x = M_PI / 2.0;
			z = atan2(rotationMatrix.at<double>(0, 1), rotationMatrix.at<double>(0, 2));
		}
		else
		{
			x = -M_PI / 2.0;
			z = atan2(-rotationMatrix.at<double>(0, 1), -rotationMatrix.at<double>(0, 2));
		}
	}
	*eulerRvecs = cv::Mat(1, 3, CV_64F);
	eulerRvecs->ptr<double>(0)[0] = x;
	eulerRvecs->ptr<double>(0)[1] = y;
	eulerRvecs->ptr<double>(0)[2] = z;
}
