#include <Engine2D/flow.h>
#include <glm/gtc/matrix_transform.hpp>

using namespace FlowEngine;
using namespace Graphics;

class Game : public Flow
{
private:
    Window* window;
    Layer* layer;
    Sprite* sprite;
    Shader* shader;
    Mask* mask;
public:
    Game() {}
    ~Game() {}

    void init() override;
    void tick() override;
    void update() override;
    void render() override;
};