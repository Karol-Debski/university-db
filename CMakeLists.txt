cmake_minimum_required(VERSION 3.28)
project(university-db VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic")

include_directories(
   ${CMAKE_SOURCE_DIR}/inc
   ${CMAKE_SOURCE_DIR}/student/inc
   ${CMAKE_SOURCE_DIR}/employee/inc
   ${CMAKE_SOURCE_DIR}/record/inc

)

set(SOURCES
   main.cpp
   student/src/student.cpp
   employee/src/employee.cpp
   
)

add_executable(${PROJECT_NAME} ${SOURCES})