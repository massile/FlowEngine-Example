cmake_minimum_required(VERSION 3.6)

link_directories(../FlowEngine/bin/Debug)
include_directories(../FlowEngine/src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(Game3D)
find_package(GLEW REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
find_library(SOIL_LIBRARY SOIL REQUIRED)

add_executable(Game3D
        Game3D/AppProvider.h
        Game3D/CameraInputComponent.h
        Game3D/CameraPhysicsComponent.h
        Game3D/LightInputComponent.h
        Game3D/MeshGraphicsComponent.h
        Game3D/World.h
        Game3D/main.cpp)
target_link_libraries(Game3D ${GLEW_LIBRARIES})
target_link_libraries(Game3D ${OPENGL_gl_LIBRARY})
target_link_libraries(Game3D ${SOIL_LIBRARY})
target_link_libraries(Game3D glfw ${GLFW_LIBRARIES})
target_link_libraries(Game3D FlowEngine)

project(Game2D)
find_package(GLEW REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
find_library(SOIL_LIBRARY SOIL REQUIRED)

add_executable(Game2D
        Game2D/main.cpp
        Game2D/Game.h
        Game2D/Game.cpp)
target_link_libraries(Game2D ${GLEW_LIBRARIES})
target_link_libraries(Game2D ${OPENGL_gl_LIBRARY})
target_link_libraries(Game2D ${SOIL_LIBRARY})
target_link_libraries(Game2D glfw ${GLFW_LIBRARIES})
target_link_libraries(Game2D FlowEngine)
