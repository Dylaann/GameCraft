#include "GameScene.h"

GameScene::GameScene()
{
}

void GameScene::start()
{
	m_grid = new Grid(m_resources);
	m_bgm1 = m_resources->getSoundResource("BGM1");
	m_bgm2 = m_resources->getSoundResource("BGM2");
	//Load the sound effects
	m_click = Mix_LoadWAV("./ASSETS/SOUNDS/click.wav");
	Mix_PlayMusic(m_bgm1, -1);
	std::vector<SDL_Texture*> bricktextures;
	bricktextures.push_back(m_resources->getImageResource("yellow"));
	bricktextures.push_back(m_resources->getImageResource("red"));
	bricktextures.push_back(m_resources->getImageResource("blue"));
	bricktextures.push_back(m_resources->getImageResource("green"));

	m_generator.setTextures(bricktextures);

	m_gameStarted = true;
}

void GameScene::stop()
{
	delete m_bgm1;
	delete m_bgm2;
	delete m_click;
}

void GameScene::update()
{
	//m_height++;
	m_generator.genBricks();
	if (m_height == 10)
	{
		Mix_FadeOutMusic(500);
		Mix_FadeInMusic(m_bgm2, -1, 250);
	}
}

void GameScene::draw(SDL_Renderer & renderer)
{
	//Draw here
	m_grid->render(&renderer);
}
