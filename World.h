#pragma once

#include <services/environment/world/IWorld.h>
#include <parse/ObjParser.h>

class World : public IWorld
{
public:
    World() {
        record("shader", new Shader("resources/shaders/basic.vert", "resources/shaders/basic.frag"));
        record("rock", ObjParser("resources/meshes/sphere.obj").parse());
        record("rocks", new TextureMap(
                new Texture("diffuseMap", "resources/textures/rocks-diffuse.jpg"),
                new Texture("specularMap", "resources/textures/rocks-spec.jpg", Texture::SPECULAR_MAP),
                new Texture("normalMap", "resources/textures/rocks-normal.jpg", Texture::NORMAL_MAP)
        ));
    }

};