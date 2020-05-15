cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME IM_AR)

project(${PROJECT_NAME} C CXX)

# c and c++ standards specified
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(./lib/googletest)

file(GLOB HEADERS src/*.h)
file(GLOB SOURCES src/*.ccp)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(test)
