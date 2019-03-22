#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Resource Manager\ResourceManager.h"
#include "Grid\Tile.h"
#include <vector>

using namespace std;

const float FRAMES_PER_SECOND = 60;
const float MAP_WIDTH = 10;
const float MAP_HEIGHT = 20;
const float TILE_WIDTH = 38;
const float TILE_HEIGHT = 33;

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

	std::vector<Tile*> m_tiles;
};
#endif // !GAME_H
