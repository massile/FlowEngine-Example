#pragma once

#include <components/physics/PhysicsComponent.h>
#include <graphics/Camera.h>

class CameraPhysicsComponent : public PhysicsComponent
{
public:
    void update(Object *object) override {
        Camera* cam = static_cast<Camera*>(object);
        cam->setVelocity(0.9f * cam->getVelocity());
    }

};