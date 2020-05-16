cmake_minimum_required(VERSION 3.1)
project(opencl-test C)

find_package(OpenCL REQUIRED)

include_directories(${OpenCL_INCLUDE_DIRS})
link_directories(${OpenCL_LIBRARY})
add_executable(cl-test src/cl.c)
target_include_directories(cl-test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cl-test ${OpenCL_LIBRARY})

