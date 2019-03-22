#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Resource Manager\ResourceManager.h"
#include "Grid\Grid.h"
#include <vector>

using namespace std;

const float FRAMES_PER_SECOND = 60;

class Game
{
public:
	// Public Functions
	Game();
	~Game();
	void run();

private:
	void processEvents();
	void update();
	void render();
	void setUpFont();

	// SDL Window
	SDL_Window * p_window;
	SDL_Renderer *m_renderer;
	int m_windowWidth = 375;
	int m_windowHeight = 667;
	bool m_exitGame = false;

	TTF_Font* Arial;

	ResourceManager * m_resourceManager;

	Grid * m_grid;
};
#endif // !GAME_H
