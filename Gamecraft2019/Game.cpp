#include "Game.h"

Game::Game() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Failed to initialise SDL" << std::endl;
	}

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (IMG_Init(imgFlags) != imgFlags)
	{
		cout << "Error: " << IMG_GetError() << endl;
	}

	// Initialize SDL_mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		cout << "Error: " << "Audio Initalisation" << endl;
	}

	p_window = SDL_CreateWindow("Game Craft", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowWidth, m_windowHeight, 0);
	m_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	if (NULL == p_window)
	{
		std::cout << "Error: Could not create window" << std::endl;
	}

	// Wait until we have assets
	m_resourceManager = new ResourceManager(m_renderer);

	while (!m_resourceManager->checkLoaded()) {
		cout << "Loading..." << endl;
	}


	m_mManager.setResourceHandler(m_resourceManager);
	setUpFont();
	//Set the scene after the systems ptr has been set and the resource manager has been passed over
	m_mManager.setScene("Menu");
}

Game::~Game()
{
}

void Game::run()
{
	const Uint32 fps = 60;
	const Uint32 minimumFrameTime = 1000 / fps;

	Uint32 frameTime = 0;
	Uint32 lastFrameTime = 0;
	//Uint32 deltaTime[[maybe_unused]] = 0;

	while (!m_exitGame) {

		processEvents();

		frameTime = SDL_GetTicks();

		//deltaTime = frameTime - lastFrameTime;
		lastFrameTime = frameTime;

		//handle input in the scenes when input is implemented
		//m_mManager.handleInput(*input);

		m_threadPool.addJob([this]() {
			update();
		});
		m_threadPool.addJob([this]() {
			render();
		});

		if ((SDL_GetTicks() - frameTime) < minimumFrameTime)
			SDL_Delay(minimumFrameTime - (SDL_GetTicks() - frameTime));
	}

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(p_window);
	SDL_Quit();
}

void Game::processEvents()
{
	m_mManager.m_current->update();
}

void Game::update()
{
	//Update the menu manager
	m_mManager.update();

	if (m_mManager.getGameOver()) {
		m_exitGame = true;
	}
}

void Game::render()
{
	if (m_renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	SDL_RenderClear(m_renderer);

	//Draw the current scene
	m_mManager.draw(*m_renderer);

	SDL_RenderPresent(m_renderer);
}


/// <summary>
/// Sets up font for game.
/// </summary>
void Game::setUpFont() {

	if (TTF_Init() < 0)
	{
		std::cout << "Error initialising font" << std::endl;
	}
	const char *path = "ASSETS\\FONTS\\arial.ttf";
	Arial = TTF_OpenFont(path, 50);
}