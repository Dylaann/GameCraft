#include "GameScene.h"

GameScene::GameScene()
{

}

void GameScene::start()
{
	brickTexture = m_resources->getImageResource("red");
	m_testbrick = new Brick(1, brickTexture, Vector2f(50, 50));
	m_testbrick->setDropped(true);
}

void GameScene::stop()
{
}

void GameScene::update()
{
	m_testbrick->update();
}

void GameScene::draw(SDL_Renderer & renderer)
{
	m_testbrick->render(renderer);
}
