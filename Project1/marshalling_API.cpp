#pragma once
#include "marshalling_API.h"

bool* CreateBooleanPointer()
{
	return new bool();
}

void  DeleteBooleanPointer(bool* pointer)
{
	delete pointer;
}



cv::Vec3d * CreateVec3dPointer()
{
	return new cv::Vec3d();
}

void DeleteVec3dPointer(cv::Vec3d * pointer)
{
	delete pointer;
}



cv::Mat * CreateMatPointer()
{
	return new cv::Mat();
}

void CreateMatDouble(cv::Mat* pointer, int rows, int cols)
{
	*pointer = cv::Mat(rows, cols, CV_64F);
}


void CreateMatInt(cv::Mat* pointer, int rows, int cols)
{
	*pointer = cv::Mat(rows, cols, CV_32S);
}

void DeleteMatPointer(cv::Mat * pointer)
{
	delete pointer;
}

double GetMatPointerOfDoubleDataAt(cv::Mat * pointer, int row, int column)
{
	return pointer->at<double>(row, column);
}

void SetMatPointerOfDoubleDataAt(cv::Mat* pointer, int row, int column, double value)
{
	pointer->ptr<double>(row)[column] = value;
}

int GetMatPointerOfIntDataAt(cv::Mat * pointer, int row, int column)
{
	return pointer->at<int>(row, column);
}

void SetMatPointerOfIntDataAt(cv::Mat* pointer, int row, int column, int value)
{
	pointer->ptr<int>(row)[column] = value;
}

int GetMatPointerRowNum(cv::Mat * pointer)
{
	return pointer->rows;
}

int GetMatPointerColNum(cv::Mat * pointer)
{
	return pointer->cols;
}
int GetMatPointerDimNum(cv::Mat * pointer)
{
	return pointer->dims;
}


// native methods that help managed c# code to marshall - std::vector<int> structure

 std::vector<int> *  CreateVectorIntPointer()
{
	return new std::vector<int>();
}

void DeleteVectorIntPointer(std::vector<int> * pointer)
{
	delete pointer;
}

int* GetVectorIntData(std::vector<int> * pointer)
{
	return pointer->data();
}

int GetVectorIntSize(std::vector<int> * pointer)
{
	return pointer->size();
}


std::vector<std::vector<int>>* CreateDoubleVectorIntPointer()
{
	return new std::vector<std::vector<int>>();
}

void DeleteDoubleVectorIntPointer(std::vector<std::vector<int>>* pointer)
{
	delete pointer;
}

std::vector<int>* GetDoubleVectorIntPointerDataAt(std::vector<std::vector<int>>* pointer, int offset)
{
	return pointer->data() + offset;
}

int GetDoubleVectorIntPointerSize(std::vector<std::vector<int>>* pointer)
{
	return pointer->size();
}

// native methods that help managed c# code to marshall -  std::vector<cv::Vec3d> structure

std::vector<cv::Vec3d> *  CreateVectorVec3dPointer()
{
	return new std::vector<cv::Vec3d>();
}

void DeleteVectorVec3dPointer(std::vector<cv::Vec3d> * pointer)
{
	delete pointer;
}

cv::Vec3d * GetVectorVec3dPointerData(std::vector<cv::Vec3d> * pointer)
{
	return pointer->data();
}

cv::Vec3d* GetVectorVec3dPointerDataAt(std::vector<cv::Vec3d>* pointer, int offset)
{
	return pointer->data() + offset;
}

int GetVectorVec3dPointerSize(std::vector<cv::Vec3d> * pointer)
{
	return pointer->size();
}


// native methods that help managed c# code to marshall - std::vector<cv::Point2f> structure

std::vector<cv::Point2f> * CreateVector2PointFPointer()
{
	return new std::vector<cv::Point2f>();
}

void DeleteVector2PointFPointer(std::vector<cv::Point2f> * pointer)
{
	delete pointer;
}

cv::Point2f * GetVector2PointFPointerData(std::vector<cv::Point2f> * pointer)
{
	return pointer->data();
}

int GetVector2PointFPointerSize(std::vector<cv::Point2f> * pointer)
{
	return pointer->size();
}


// native methods that help managed c# code to marshall - std::vector<std::vector<cv::Point2f>> structure

std::vector<std::vector<cv::Point2f>> *  CreateDoubleVector2PointFPointer()
{
	return new std::vector<std::vector<cv::Point2f>>();
}

 void  DeleteDoubleVector2PointFPointer(std::vector<std::vector<cv::Point2f>> * pointer)
{
	delete pointer;
}

std::vector<cv::Point2f> * GetDoubleVector2PointFPointerData(std::vector<std::vector<cv::Point2f>> * pointer)
{
	return pointer->data();
}
std::vector<cv::Point2f> * GetDoubleVector2PointFPointerDataAt(std::vector<std::vector<cv::Point2f>> * pointer, int offset)
{
	return pointer->data() + offset;
}

int GetDoubleVector2PointFPointerSize(std::vector<std::vector<cv::Point2f>> * pointer)
{
	return pointer->size();
}


// native methods that help managed c# code to marshall - std::vector<cv::Point3f> structure

std::vector<cv::Point3f> * CreateVector3PointFPointer()
{
	return new std::vector<cv::Point3f>();
}

void  DeleteVector3PointFPointer(std::vector<cv::Point3f> * pointer)
{
	delete pointer;
}

cv::Point3f * GetVector3PointFPointerData(std::vector<cv::Point3f> * pointer)
{
	return pointer->data();
}

int GetVector3PointFPointerSize(std::vector<cv::Point3f> * pointer)
{
	return pointer->size();
}



std::vector<std::vector<cv::Point3f>> *  CreateDoubleVector3PointFPointer()
{
	return new std::vector<std::vector<cv::Point3f>>();
}

 void  DeleteDoubleVector3PointFPointer(std::vector<std::vector<cv::Point3f>> * pointer)
{
	delete pointer;
}

std::vector<cv::Point3f> *  GetDoubleVector3PointFPointerData(std::vector<std::vector<cv::Point3f>> * pointer)
{
	return pointer->data();
}

std::vector<cv::Point3f> *  GetDoubleVector3PointFPointerDataAt(std::vector<std::vector<cv::Point3f>> * pointer, int offset)
{
	return pointer->data() + offset;
}

int  GetDoubleVector3PointFPointerSize(std::vector<std::vector<cv::Point3f>> * pointer)
{
	return pointer->size();
}