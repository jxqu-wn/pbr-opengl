#pragma once

#include <glad/gl.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
public:
    // program id
    unsigned int id;

    Shader(const char* vertexPath, const char* fragmentPath);
    // Shader(const std::string vertexPath, const std::string fragmentPath);
    void use();
    // uniform functions
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;

private:
    int compileShader(unsigned int& shader, const char* source, GLenum type);
};