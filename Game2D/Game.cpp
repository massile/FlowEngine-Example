
#include "Game.h"

void Game::init()
{
    window = createWindow("Test Game", 1200, 1200*9.0/16.0);
    shader = new Shader("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");

    BatchRenderer2D* renderer = new BatchRenderer2D(glm::vec2(window->getWidth(), window->getHeight()));
    layer = new Layer(renderer, shader, glm::ortho(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
    sprite = new Sprite(0.0f, 0.0f, 4, 4, new Texture("diffuse", "resources/textures/brick-diffuse.jpg"));

    layer->add(sprite);

    Texture::setWrapMode(TextureWrap::CLAMP);
    mask = new Mask(new Texture("Mask", "resources/textures/rock-diffuse.jpg"));
    layer->setMask(mask);

    renderer->addPostEffectPass(new PostEffectPass(new Shader("resources/shaders/postfx.vert", "resources/shaders/postfx.frag")));
}

void Game::tick()
{
    std::cout << getUPS() << " ups, " << getFPS() << " fps" << std::endl;
}

void Game::update()
{
    float speed = 0.1f;

    if (window->isKeyPressed(GLFW_KEY_UP)) {
        glm::vec3 position = sprite->getPosition();
        sprite->setPosition(position + glm::vec3(0, speed, 0));
    }
    if (window->isKeyPressed(GLFW_KEY_DOWN)) {
        glm::vec3 position = sprite->getPosition();
        sprite->setPosition(position + glm::vec3(0, -speed, 0));
    }
    if (window->isKeyPressed(GLFW_KEY_LEFT)) {
        glm::vec3 position = sprite->getPosition();
        sprite->setPosition(position + glm::vec3(-speed, 0, 0));
    }
    if (window->isKeyPressed(GLFW_KEY_RIGHT)) {
        glm::vec3 position = sprite->getPosition();
        sprite->setPosition(position + glm::vec3(speed, 0, 0));
    }

    glm::vec2 pos = window->getMousePosition();
    shader->enable();
    shader->uniform("light_pos", glm::vec2(pos.x * 32.0f / window->getWidth() - 16.0f, 9.0f - pos.y * 18.0f / window->getHeight()));
    shader->disable();
}

void Game::render()
{
    layer->render();
}
