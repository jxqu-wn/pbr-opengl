#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <string>

#include "shader.h"

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Texture{
    unsigned int id;
    std::string type;
};

class Mesh{
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);

    void draw(Shader shader);

private:
    unsigned int vao, vbo, ebo;
    void setupMesh();
};