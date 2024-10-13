
cmake_minimum_required(VERSION 3.10)

project(${PRJ_NAME})

set(CMAKE_C_COMPILER gcc)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)


set(PRJ_PATH ${CMAKE_SOURCE_DIR}/../..)

file(GLOB SOURCES "${PRJ_PATH}/source/*.c")

message(STATUS ${PRJ_PATH})
include_directories(
    "${PRJ_PATH}/include/"
)

add_executable(${PRJ_NAME} ${SOURCES})
