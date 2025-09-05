cmake_minimum_required(VERSION 3.11)

project(FSolution)

add_executable(${PROJECT_NAME}
	./main.c
	./source/arrgen.c
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
