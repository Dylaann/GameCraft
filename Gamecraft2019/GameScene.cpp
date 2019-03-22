#include "GameScene.h"

GameScene::GameScene()
{

}

void GameScene::start()
{
	m_grid = new Grid(m_resources);
	brickTexture = m_resources->getImageResource("red");
	m_testbrick = new Brick(3, brickTexture, Vector2f(38, 33));
	//m_testbrick->setDropped(false);
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
	m_testbrick->update();
	//m_height++;
	m_generator.genBricks();
	if (m_height == 10)
	{
		Mix_FadeOutMusic(500);
		Mix_FadeInMusic(m_bgm2, -1, 250);
	}

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_UP)
				std::cout << "UP PRESSED" << std::endl;

			if (event.key.keysym.sym == SDLK_DOWN)
				std::cout << "DOWN PRESSED" << std::endl;

			if (event.key.keysym.sym == SDLK_LEFT)
				std::cout << "LEFT PRESSED" << std::endl;

			if (event.key.keysym.sym == SDLK_RIGHT)
				std::cout << "RIGHT PRESSED" << std::endl;

			if (event.key.keysym.sym == SDLK_SPACE)
				std::cout << "WANkers" << std::endl;
  				m_testbrick->setDropped(true);
		default:
			break;
		}
	}
}

void GameScene::draw(SDL_Renderer & renderer)
{
	//Draw here
	m_grid->render(&renderer);
	m_testbrick->render(renderer);
}
