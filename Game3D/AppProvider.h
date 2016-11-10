#pragma once

#include <Engine3D/providers/Provider.h>
#include <Engine3D/services/ui/window/Window.h>
#include "World.h"

class AppProvider : public Provider
{
public:
    AppProvider() : Provider {}

    void record() override {
        Environment::provide(new World(), new Graphics());
    }
};