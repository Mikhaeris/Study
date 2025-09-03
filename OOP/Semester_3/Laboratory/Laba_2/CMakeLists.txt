cmake_minimum_required(VERSION 3.11)

project(Precipitation)

add_executable(${PROJECT_NAME}
	./main.cpp
	./source/precipitation.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)
