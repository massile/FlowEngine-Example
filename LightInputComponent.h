#pragma once

#include <components/input/InputComponent.h>
#include <graphics/Camera.h>
#include <services/input/keyboard/IKeyboard.h>
#include <services/input/Input.h>

using namespace glm;

class LightInputComponent : public InputComponent
{
public:
    virtual void update(Object *object, float dt) override {
        Light* light = static_cast<Light*>(object);
        GLfloat speed = 3.0f * dt;

        IKeyboard* keyboard = Input::getKeyboard();
        if(keyboard->isKeyPressed(GLFW_KEY_UP))
            light->translate(vec3(0, speed, 0));
        if(keyboard->isKeyPressed(GLFW_KEY_DOWN))
            light->translate(vec3(0, -speed, 0));
        if(keyboard->isKeyPressed(GLFW_KEY_LEFT))
            light->translate(vec3(speed, 0, 0));
        if(keyboard->isKeyPressed(GLFW_KEY_RIGHT))
            light->translate(vec3(-speed, 0, 0));
    }
};