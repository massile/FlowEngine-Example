cmake_minimum_required(VERSION 3.6)

link_directories(bin/)
include_directories(../FlowEngine/src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Game3D)
add_executable(Game3D
        Game3D/AppProvider.h
        Game3D/CameraInputComponent.h
        Game3D/CameraPhysicsComponent.h
        Game3D/LightInputComponent.h
        Game3D/MeshGraphicsComponent.h
        Game3D/World.h
        Game3D/main.cpp)
target_link_libraries(Game3D FlowEngine)

project(Game2D)
add_executable(Game2D
        Game2D/main.cpp)
target_link_libraries(Game2D FlowEngine)
