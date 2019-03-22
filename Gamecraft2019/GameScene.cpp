#include "GameScene.h"

GameScene::GameScene()
{

}

void GameScene::start()
{
<<<<<<< HEAD
	brickTexture = m_resources->getImageResource("red");
	m_testbrick = new Brick(1, brickTexture, Vector2f(50, 50));
	m_testbrick->setDropped(true);
=======
	m_bgm1 = m_resources->getSoundResource("BGM1");
	m_bgm2 = m_resources->getSoundResource("BGM2");
	//Load the sound effects
	m_click = Mix_LoadWAV("./ASSETS/SOUNDS/click.wav");
	Mix_PlayMusic(m_bgm1, -1);
	m_gameStarted = true;
>>>>>>> 58cf4199c69c072d5a13b528917a6fe1bedd76a4
}

void GameScene::stop()
{
	delete m_bgm1;
	delete m_bgm2;
	delete m_click;
}

void GameScene::update()
{
<<<<<<< HEAD
	m_testbrick->update();
=======
	//m_height++;
	if (m_height == 10)
	{
		Mix_FadeOutMusic(500);
		Mix_FadeInMusic(m_bgm2, -1, 250);
	}
>>>>>>> 58cf4199c69c072d5a13b528917a6fe1bedd76a4
}

void GameScene::draw(SDL_Renderer & renderer)
{
	m_testbrick->render(renderer);
}
