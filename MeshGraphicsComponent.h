#pragma once

#include <components/graphics/GraphicsComponent.h>

class MeshGraphicsComponent : public GraphicsComponent
{
public:
    MeshGraphicsComponent() {}
    virtual void update(Object *object, IWorld *world, Graphics *graphics) override {
        TextureMap* rocksTexture = world->getTexture("rocks");
        Shader* shader = world->getShader("shader");

        rocksTexture->use(*shader);
        Mesh* obj = world->getMesh("rock");
        graphics->render(obj);
    }

};