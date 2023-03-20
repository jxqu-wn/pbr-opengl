// #define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "shader.h"

int main(){
    // GLFW initialization
    if(!glfwInit()){
        std::cout << "GLFW failed to init." << std::endl;
    }
    else{
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    // create GLFW window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "PBR Learning", NULL, NULL);
    if(!window){
        std::cout << "GLFW window failed to create." << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // glad initialization
    if(!gladLoadGL(glfwGetProcAddress)){
        std::cout << "glad failed to init." << std::endl;
        return -1;
    }

    Shader shader("/home/jxqu/Projects/Graphics/OpenGL/src/nothing.vert", "/home/jxqu/Projects/Graphics/OpenGL/src/nothing.frag");

    // render loop
    while(!glfwWindowShouldClose(window)){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}