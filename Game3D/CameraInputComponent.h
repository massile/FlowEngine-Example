#pragma once

#include <Engine3D/components/input/InputComponent.h>
#include <Engine3D/graphics/Camera.h>
#include <Engine3D/services/input/keyboard/IKeyboard.h>
#include <Engine3D/services/input/Input.h>

using namespace glm;

class CameraInputComponent : public InputComponent
{
public:
    virtual void update(Object *object, float dt) override {
        Camera* cam = static_cast<Camera*>(object);
        GLfloat speed = 1.0f * dt;

        IKeyboard* keyboard = Input::getKeyboard();
        if(keyboard->isKeyPressed('W'))
            cam->setVelocityLocal(vec3(0, 0, speed));
        if(keyboard->isKeyPressed('S'))
            cam->setVelocityLocal(vec3(0, 0, -speed));
        if(keyboard->isKeyPressed('A'))
            cam->setVelocityLocal(vec3(speed, 0, 0));
        if(keyboard->isKeyPressed('D'))
            cam->setVelocityLocal(vec3(-speed, 0, 0));
        if(keyboard->isKeyPressed(GLFW_KEY_SPACE))
            cam->setVelocityLocal(vec3(0, speed, 0));

        cam->translate(cam->getVelocity());
        vec2 offset = SENSITIVITY * Input::getMouse()->getCursorPositionOffset();
        GLfloat yaw = cam->getYaw();
        GLfloat pitch = cam->getPitch();

        cam->setYaw(yaw + dt * offset.x);
        cam->setPitch(pitch + dt * offset.y);

        yaw = radians(cam->getYaw());
        pitch = radians(cam->getPitch());

        cam->setFront(vec3(cos(yaw) * cos(pitch), sin(pitch), sin(yaw) * cos(pitch)));
        cam->lookAt(cam->getPosition() + cam->getFront());
    }
};