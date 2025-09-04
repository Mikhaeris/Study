cmake_minimum_required(VERSION 3.11)

project(Vector)

add_executable(${PROJECT_NAME}
	./main.cpp
	./source/square.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)
