#include "GameScene.h"

GameScene::GameScene()
{

}

void GameScene::start()
{
	srand(time(NULL));
	if (TTF_Init() < 0)
	{
		std::cout << "Error initialising font" << std::endl;
	}
	const char *path = "ASSETS\\FONTS\\arial.ttf";
	Arial = TTF_OpenFont(path, 50);
	std::string temp= "Score: " + std::to_string(m_score);

	surfaceMessage = TTF_RenderText_Blended(Arial, temp.c_str(), m_scoreCol);
	m_message_rect.x = float(0);
	m_message_rect.y = float(0);

	m_message_rect.w = 200;
	m_message_rect.h = 70;

	m_grid = new Grid(m_resources);
	brickTexture = m_resources->getImageResource("blue");
	int k = rand() % 7;
	m_testbrick = new Brick(3, brickTexture, Vector2f(37.5 * k, 76));
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
	m_testbrick->update(m_stack, m_score);
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
			if (event.key.keysym.sym == SDLK_UP) {
			}

			if (event.key.keysym.sym == SDLK_DOWN) {
			}

			if (event.key.keysym.sym == SDLK_LEFT) {
			}

			if (event.key.keysym.sym == SDLK_RIGHT) {
			}

			if (event.key.keysym.sym == SDLK_SPACE) {
				m_testbrick->setDropped(true);
			}
		default:
			break;
		}
	}

	if (m_testbrick->getDone()) {
		for (int i = 0; i < m_testbrick->getBlockSize(); i++) {
			m_grid->setTileState(m_testbrick->getPosition().x + (i * 37.5), m_testbrick->getPosition().y, "OldTile");
		}

		if (m_stack <= 10) {
			m_stack += 1;
			m_score += 1;
		}
		else {
			m_grid->moveTiles();
			m_score += 1;
		}

		m_testbrick->setBlockSize(m_testbrick->getBlockSize() - m_grid->checkMiss());
		m_currentBrickLen = m_testbrick->getBlockSize();

		if (m_currentBrickLen < 1) {
			m_gameOver = true;
		}

		int k = rand() % 7;
		m_testbrick = new Brick(m_currentBrickLen, brickTexture, Vector2f(37.5 * k, 76));
	}
	else {
		for (int i = 0; i < m_testbrick->getBlockSize(); i++) {
		}
	}

}

void GameScene::draw(SDL_Renderer & renderer)
{
	//Draw here
	SDL_DestroyTexture(m_message);
	std::string temp = "Score: " + std::to_string(m_score);
	surfaceMessage = TTF_RenderText_Blended(Arial, temp.c_str(), m_scoreCol);
	m_message = SDL_CreateTextureFromSurface(&renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	m_grid->render(&renderer);
	if (!m_testbrick->getDone()) {
		m_testbrick->render(renderer);
	}

	SDL_RenderCopy(&renderer, m_message, NULL, &m_message_rect);
}
