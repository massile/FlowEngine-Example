#pragma once

#include <providers/Provider.h>
#include "World.h"

class AppProvider : public Provider
{
public:
    AppProvider() : Provider(new Window("Test", 800, 800)) {}

    void record() override {
        Environment::provide(new World(), new Graphics());
    }
};