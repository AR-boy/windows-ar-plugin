#pragma once
#include "platform.h"
#include <vector>
#include <iostream>
#include <opencv2\core\types.hpp>
#include <opencv2\aruco.hpp>
#include <opencv2\imgproc.hpp>


extern "C" {

	UNITY_API void DetectMarkers(
		unsigned char* textureData,
		int width,
		int height,
		std::vector<int>* markerIds,
		std::vector<std::vector<cv::Point2f>>* markers,
		std::vector<std::vector<cv::Point2f>>* rejectedMarkers
	);
}