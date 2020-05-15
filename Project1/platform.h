#ifndef UNITY_API
#define UNITY_API

#ifdef _WIN32
#define UNITY_API __declspec(dllimport)
#else
#define UNITY_API
#endif

#endif