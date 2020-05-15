#pragma once
#include "platform.h"

#include <vector>
#include <iostream>
#include <opencv2\core\types.hpp>
#include <opencv2\aruco\charuco.hpp>
#include <opencv2\aruco.hpp>
#include <opencv2\opencv.hpp>


extern "C" {

	UNITY_API void EstimateCharucoBoardPose(
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
	);
}