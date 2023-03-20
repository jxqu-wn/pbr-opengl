cmake_minimum_required(VERSION 3.10)

project(opengl_pbr_study)

set(CMAKE_CXX_STANDARD 17)

set(SRC 
src/main.cpp
src/shader.cpp
src/gl.c)

# include file
include_directories(include)

# lib file
link_directories(lib bin)

# create executable file
add_executable(${PROJECT_NAME} ${SRC})

# find and link x11 library
find_package(X11 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_LIBRARIES})

# find glfw library
find_library(GLFW_LIBRARY glfw3 lib)
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARY})

# find and link assimp
find_library(ASSIMP_LIBRARY NAMES assimp assimp bin)
target_link_libraries(${PROJECT_NAME} PRIVATE ${ASSIMP_LIBRARY})