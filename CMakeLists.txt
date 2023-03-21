cmake_minimum_required(VERSION 3.10)

project(opengl_pbr_study)

set(CMAKE_CXX_STANDARD 17)

set(SRC 
src/main.cpp
src/shader.cpp
src/gl.c)

include_directories(include)

# OpenGL
find_package(OpenGL REQUIRED)
if(OpengGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIRS})
endif()

# assimp
find_package(ASSIMP REQUIRED)
if(ASSIMP_FOUND)
    include_directories(${ASSIMP_INCLUDE_DIR})
endif()

# glfw
find_package(glfw3 3.3 REQUIRED)
if(GLFW3_FOUND)
    include_directories(${GLFW3_INCLUDE_DIR})
endif()

# create executable file
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include> $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} PUBLIC glfw OpenGL::GL ${CMAKE_DL_LIBS})
