#pragma once
#include "platform.h"
#include <vector>
#include <iostream>
#include <opencv2\core\types.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\aruco.hpp>
#include <opencv2\aruco\charuco.hpp>
#include <opencv2\calib3d.hpp>


extern "C" {

	UNITY_API void DetectCharucoBoard(
		unsigned char* textureData,
		int width,
		int height,
		int squaresW,
		int squaresH,
		float squareLength,
		float markersLength,
		bool* boarDetected,
		std::vector<std::vector<int>>* allCharucoIds,
		std::vector<std::vector<cv::Point2f>>* allCharucoCorners
	);

	UNITY_API double CalibrateCameraCharuco(
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
	);

}