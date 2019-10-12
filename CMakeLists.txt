cmake_minimum_required(VERSION 3.0)
project( hhh VERSION 0.1.0)


find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( hh ${PROJECT_SOURCE_DIR}/hh.cpp )
target_link_libraries( hh ${OpenCV_LIBS} )