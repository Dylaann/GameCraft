#include "GameScene.h"


void producer(GameScene * scene, int n)
{
	int count = n;

	while (true) {
		if (scene->m_q1.size() < count) {
			std::unique_lock<std::mutex> lck(scene->mx);
			int k = rand() % 7;
			Brick * m_temp = new Brick(1, scene->brickTexture, Vector2f(37.5 * k, 76));
			scene->m_q1.push_front(m_temp);
			scene->produced++;
			lck.unlock();
			scene->cv.notify_one();
		}
		else if (scene->m_q2.size() < count) {
			std::unique_lock<std::mutex> lck(scene->mx);
			int k = rand() % 7;
			Brick * m_temp = new Brick(2, scene->brickTexture, Vector2f(37.5 * k, 76));
			scene->m_q2.push_front(m_temp);
			scene->produced++;
			lck.unlock();
			scene->cv.notify_one();
		}
		else if (scene->m_q3.size() < count) {
			std::unique_lock<std::mutex> lck(scene->mx);
			int k = rand() % 7;
			Brick * m_temp = new Brick(3, scene->brickTexture, Vector2f(37.5 * k, 76));
			scene->m_q3.push_front(m_temp);
			scene->produced++;
			lck.unlock();
			scene->cv.notify_one();
		}
	}
}

void consumer(GameScene * scene)
{
	while (true) {
		std::unique_lock<std::mutex> lck(scene->mx);
		scene->cv.wait(lck, [scene]() { 
			return scene->m_currentbrick == nullptr; });
		if (scene->m_currentBrickLen == 1) {
			scene->m_currentbrick = scene->m_q1.back();
			scene->m_q1.pop_back();
		}
		else if (scene->m_currentBrickLen == 2) {
			scene->m_currentbrick = scene->m_q2.back();
			scene->m_q2.pop_back();
		}
		else if (scene->m_currentBrickLen == 3) {
			scene->m_currentbrick = scene->m_q3.back();
			scene->m_q3.pop_back();
		}
		scene->consumed++;
		lck.unlock();
	}
}


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

	m_currentbrick = nullptr;
	brickTexture = m_resources->getImageResource("blue");

	if (!threadsMade) {
		producerThread = std::move(std::thread(&producer, this, 1));
		consumerThread = std::move(std::thread(&consumer, this));
		threadsMade = true;
	}

	m_stack = 1;
	m_currentBrickLen = 3;
	m_score = 0;
	std::string temp= "Score: " + std::to_string(m_score);

	surfaceMessage = TTF_RenderText_Blended(Arial, temp.c_str(), m_scoreCol);
	m_message_rect.x = float(0);
	m_message_rect.y = float(0);

	m_message_rect.w = 200;
	m_message_rect.h = 70;

	m_grid = new Grid(m_resources);


	//int k = rand() % 7;
	//m_currentbrick = new Brick(3, brickTexture, Vector2f(37.5 * k, 76));
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

	m_leaderboard = new LeaderBoard();

	m_gameOver = false;
}

void GameScene::stop()
{
	//delete m_bgm1;
	//delete m_bgm2;
	//delete m_click;
}

void GameScene::update()
{
	if (m_currentbrick == nullptr) {
		std::cout << "";
	}
	m_currentbrick->update(m_stack, m_score);
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
				m_currentbrick->setDropped(true);
			}
		default:
			break;
		}
	}

	if (m_currentbrick->getDone()) {
		for (int i = 0; i < m_currentbrick->getBlockSize(); i++) {
			m_grid->setTileState(m_currentbrick->getPosition().x + (i * 37.5), m_currentbrick->getPosition().y, "OldTile");
		}

		if (m_stack <= 10) {
			m_stack += 1;
			m_score += 1;
		}
		else {
			m_grid->moveTiles();
			m_score += 1;
		}

		m_currentbrick->setBlockSize(m_currentbrick->getBlockSize() - m_grid->checkMiss());
		m_currentBrickLen = m_currentbrick->getBlockSize();

		if (m_currentBrickLen < 1) {
			
			std::cout << "Enter Name: " << std::endl;
			std::string name;
			std::cin >> name;
			m_leaderboard->save(name, m_score);
			m_gameOver = true;
		}
	

		//int k = rand() % 7;
		m_currentbrick = nullptr;
		cv.notify_one();
	}
	else {
		for (int i = 0; i < m_currentbrick->getBlockSize(); i++) {
		}
	}

	if (m_gameOver == true)
	{
		goToScene("Menu");
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
	if (m_currentbrick != nullptr) {
		if (!m_currentbrick->getDone()) {
			m_currentbrick->render(renderer);
		}
	}

	SDL_RenderCopy(&renderer, m_message, NULL, &m_message_rect);
}