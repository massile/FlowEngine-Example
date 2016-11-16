cmake_minimum_required(VERSION 3.6)

link_directories(../FlowEngine/bin/Debug)
include_directories(../FlowEngine/src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Game)
find_package(GLEW REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
find_library(SOIL_LIBRARY SOIL REQUIRED)

add_executable(Game
        Game/main.cpp
        Game/Game.h
        Game/Game.cpp)
add_definitions(-Dinterface=class)
target_link_libraries(Game ${GLEW_LIBRARIES})
target_link_libraries(Game ${OPENGL_gl_LIBRARY})
target_link_libraries(Game ${SOIL_LIBRARY})
target_link_libraries(Game glfw ${GLFW_LIBRARIES})
target_link_libraries(Game FlowEngine)
