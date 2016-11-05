cmake_minimum_required(VERSION 3.6)
project(Game)
link_directories(bin/)
include_directories(../FlowEngine/src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB SOURCE_FILES "*.h" "*.cpp")

add_executable(Game ${SOURCE_FILES})
target_link_libraries(Game FlowEngine)
