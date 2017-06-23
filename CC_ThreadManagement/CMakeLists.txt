cmake_minimum_required(VERSION 3.6)
project(CC_ThreadManagement)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(CC_ThreadManagement ${SOURCE_FILES})
target_link_libraries(CC_ThreadManagement pthread)