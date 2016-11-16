#include <flow.h>
#include <glm/gtc/matrix_transform.hpp>

using namespace FlowEngine;
using namespace Graphics;

class Game : public Flow
{
private:
    Window* window = createWindow("Test Game", 1200, 1200*9.0/16.0);

    Layer3D* layer = new Layer3D(new ForwardRenderer, new Scene);
    Shader* shader = new Shader("resources/shaders/basic_3d.vert", "resources/shaders/basic_3d.frag");
    Mesh* cube;

    float rotate = 0.0f;
public:
    Game() {}
    ~Game() {}

    void init() override;
    void tick() override;
    void update() override;
    void render() override;
};