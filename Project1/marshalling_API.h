#pragma once
#include "platform.h"

// opencv imports
#include <opencv2/calib3d.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/aruco/charuco.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

extern "C" {

	UNITY_API bool* CreateBooleanPointer();

	UNITY_API void   DeleteBooleanPointer(bool* pointer);

	UNITY_API cv::Vec3d*  CreateVec3dPointer();

	UNITY_API void   DeleteVec3dPointer(cv::Vec3d* pointer);


	// c# helper mashal methods for - cv::Mat structure
	UNITY_API cv::Mat*  CreateMatPointer();

	UNITY_API void CreateMatDouble(cv::Mat* pointer, int rows, int cols);

	UNITY_API void CreateMatInt(cv::Mat* pointer, int rows, int cols);

	UNITY_API void  DeleteMatPointer(cv::Mat* pointer);

	UNITY_API double  GetMatPointerOfDoubleDataAt(cv::Mat* pointer, int row, int column);

	UNITY_API void SetMatPointerOfDoubleDataAt(cv::Mat* pointer, int row, int column, double value);

	UNITY_API int  GetMatPointerOfIntDataAt(cv::Mat* pointer, int row, int column);

	UNITY_API void SetMatPointerOfIntDataAt(cv::Mat* pointer, int row, int column, int value);

	UNITY_API int  GetMatPointerRowNum(cv::Mat* pointer);
	
	UNITY_API int  GetMatPointerColNum(cv::Mat* pointer);

	UNITY_API int  GetMatPointerDimNum(cv::Mat* pointer);



	// c# helper mashal methods for - std::vector<int> structure
	UNITY_API std::vector<int>*  CreateVectorIntPointer();

	UNITY_API void  DeleteVectorIntPointer(std::vector<int>* pointer);

	UNITY_API int*  GetVectorIntData(std::vector<int>* pointer);

	UNITY_API int   GetVectorIntSize(std::vector<int>* pointer);

	// c# helper mashal methods for - std::vector<int> structure

	UNITY_API std::vector<std::vector<int>>* CreateDoubleVectorIntPointer();

	UNITY_API void DeleteDoubleVectorIntPointer(std::vector<std::vector<int>>* pointer);

	UNITY_API std::vector<int>* GetDoubleVectorIntPointerDataAt(std::vector<std::vector<int>>* pointer, int offset);

	UNITY_API int GetDoubleVectorIntPointerSize(std::vector<std::vector<int>>* pointer);

	// native methods that help managed c# code to marshall -  std::vector<cv::Vec3d> structure

	UNITY_API std::vector<cv::Vec3d>*  CreateVectorVec3dPointer();

	UNITY_API void  DeleteVectorVec3dPointer(std::vector<cv::Vec3d>* pointer);

	UNITY_API cv::Vec3d *  GetVectorVec3dPointerData(std::vector<cv::Vec3d> * pointer);

	UNITY_API cv::Vec3d * GetVectorVec3dPointerDataAt(std::vector<cv::Vec3d>* pointer, int offset);

	UNITY_API int  GetVectorVec3dPointerSize(std::vector<cv::Vec3d>* pointer);


	// native methods that help managed c# code to marshall - std::vector<cv::Point2f> structure

	UNITY_API std::vector<cv::Point2f>*  CreateVector2PointFPointer();

	UNITY_API void  DeleteVector2PointFPointer(std::vector<cv::Point2f>* pointer);

	UNITY_API cv::Point2f*  GetVector2PointFPointerData(std::vector<cv::Point2f>* pointer);

	UNITY_API int  GetVector2PointFPointerSize(std::vector<cv::Point2f>* pointer);



	// native methods that help managed c# code to marshall - std::vector<std::vector<cv::Point2f>> structure

	UNITY_API std::vector<std::vector<cv::Point2f>> *  CreateDoubleVector2PointFPointer();

	UNITY_API void  DeleteDoubleVector2PointFPointer(std::vector<std::vector<cv::Point2f>> * pointer);

	UNITY_API std::vector<cv::Point2f> *  GetDoubleVector2PointFPointerData(std::vector<std::vector<cv::Point2f>> * pointer);

	UNITY_API std::vector<cv::Point2f> *  GetDoubleVector2PointFPointerDataAt(std::vector<std::vector<cv::Point2f>> * pointer, int offset);

	UNITY_API int   GetDoubleVector2PointFPointerSize(std::vector<std::vector<cv::Point2f>> * pointer);



	// native methods that help managed c# code to marshall - std::vector<cv::Point3f> structure
	UNITY_API std::vector<cv::Point3f> *  CreateVector3PointFPointer();

	UNITY_API void  DeleteVector3PointFPointer(std::vector<cv::Point3f> * pointer);

	UNITY_API  cv::Point3f *  GetVector3PointFPointerData(std::vector<cv::Point3f> * pointer);

	UNITY_API int GetVector3PointFPointerSize(std::vector<cv::Point3f> * pointer);


	// native methods that help managed c# code to marshall - std::vector<std::vector<cv::Point3f>> structure
	UNITY_API std::vector<std::vector<cv::Point3f>> *  CreateDoubleVector3PointFPointer();

	UNITY_API void  DeleteDoubleVector3PointFPointer(std::vector<std::vector<cv::Point3f>> * pointer);

	UNITY_API std::vector<cv::Point3f> *  GetDoubleVector3PointFPointerData(std::vector<std::vector<cv::Point3f>> * pointer);

	UNITY_API std::vector<cv::Point3f> *  GetDoubleVector3PointFPointerDataAt(std::vector<std::vector<cv::Point3f>> * pointer, int offset);

	UNITY_API int GetDoubleVector3PointFPointerSize(std::vector<std::vector<cv::Point3f>> * pointer);

};