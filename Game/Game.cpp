#include <factories/MeshFactory.h>
#include "Game.h"

void Game::init()
{
    cube = MeshFactory::generateCube(2.0f);
    layer->getScene()->add(cube);

    shader->enable();
    shader->uniform("pr_matrix", glm::perspective(65.0f, 16.0f/9, 0.1f, 1000.0f));
    shader->uniform("vw_matrix", glm::translate(glm::mat4(), glm::vec3(2.0f, 5.0f, -10.0f)));
    shader->uniform("ml_matrix", glm::mat4());
}

void Game::tick()
{
    std::cout << getUPS() << " ups, " << getFPS() << " fps" << std::endl;
}

void Game::update()
{
    shader->uniform("ml_matrix", glm::rotate(glm::mat4(), rotate, glm::vec3(1, 1, 1)));
    rotate += 0.02f;
}

void Game::render()
{
    layer->render();
}