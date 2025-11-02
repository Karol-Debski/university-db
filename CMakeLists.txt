cmake_minimum_required(VERSION 3.28)
project(university-db VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic")

include_directories(
   ${CMAKE_SOURCE_DIR}/builders/inc
   ${CMAKE_SOURCE_DIR}/builders/types/inc
   ${CMAKE_SOURCE_DIR}/console-ui/inc
   ${CMAKE_SOURCE_DIR}/database/inc
   ${CMAKE_SOURCE_DIR}/record/inc
   ${CMAKE_SOURCE_DIR}/record/types/inc
)

set(SOURCES
   main.cpp
   builders/src/record_builder.cpp
   builders/types/src/employee_builder.cpp
   builders/types/src/student_builder.cpp
   console-ui/src/console_ui.cpp
   database/src/database.cpp
   record/types/src/student.cpp
   record/types/src/employee.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})