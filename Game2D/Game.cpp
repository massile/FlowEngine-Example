
#include "Game.h"

void Game::init()
{
    window = createWindow("Test Game", 960, 540);
    shader = new Shader("resources/shaders/basic_2d.vert", "resources/shaders/basic_2d.frag");
    layer = new Layer(new BatchRenderer2D(), shader, glm::ortho(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
    sprite = new Sprite(0.0f, 0.0f, 4, 4, new Texture("diffuse", "resources/textures/brick-diffuse.jpg"));

    layer->add(sprite);
    layer->add(new Sprite(-16.0f, -9.0f, 32, 32, 0xffff00ff));

    Texture::setWrapMode(TextureWrap::CLAMP);
    layer->setMask(new Texture("Mask", "resources/textures/rocks-spec.jpg"));

    shader->enable();
    shader->uniform("maskMatrix", glm::translate(glm::mat4(1.0f), mask));
}

void Game::tick()
{
    std::cout << getUPS() << " ups, " << getFPS() << " fps" << std::endl;
}

void Game::update()
{
    float speed = 0.01f;

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
    shader->uniform("light_pos", glm::vec2(pos.x * 32.0f / window->getWidth() - 16.0f, 9.0f - pos.y * 18.0f / window->getHeight()));
}

void Game::render()
{
    layer->render();
}
