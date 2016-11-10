#include "AppProvider.h"
#include "MeshGraphicsComponent.h"
#include "CameraPhysicsComponent.h"
#include "CameraInputComponent.h"
#include "LightInputComponent.h"
#include <Engine3D/components/shader/CameraShaderComponent.h>
#include <Engine3D/components/shader/LightShaderComponent.h>

int main()
{
    AppProvider appProvider;
    appProvider.record();

    Shader* shader = Environment::getWorld()->getShader("shader");

    Camera *cam = new Camera(new CameraInputComponent(), new CameraPhysicsComponent(), new CameraShaderComponent());
    cam->translate(glm::vec3(-2, 0, 0));
    cam->setYaw(70.0f);

    Light light(new LightInputComponent(), nullptr, new LightShaderComponent());
    light.translate(glm::vec3(-2, 4, 0));

    Object obj(nullptr, nullptr, nullptr, new MeshGraphicsComponent());

    appProvider.registerCamera(cam);
    appProvider.registerLight(light);
    appProvider.registerPerFrame(obj);

    appProvider.run(*shader);
    return 0;
}