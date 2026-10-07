cmake_minimum_required(VERSION 4.4.4)

project(Courses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(courses src/main.cpp)

target_sources(courses PRIVATE
    src/Course.cpp
    src/CourseDao.cpp
    src/CourseService.cpp
    src/CourseController.cpp
    src/CourseRequests.cpp
    src/exceptions/DuplicateCourseException.cpp
    src/exceptions/CourseNotFoundException.cpp
)

target_include_directories(courses PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions
)
