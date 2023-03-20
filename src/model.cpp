#include "model.h"

Model::Model(char* path){
    loadModel(path);
}

void Model::loadModel(std::string path){
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
}

void Model::draw(Shader shader){
    for(auto& mesh : meshes){
        mesh.draw(shader);
    }
}