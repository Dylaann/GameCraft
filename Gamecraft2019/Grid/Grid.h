#ifndef GRID_H
#define GRID_H

#include <SDL.h>
#include <iostream>
#include "../Resource Manager/ResourceManager.h"
#include "Tile.h"
#include <string.h>

class Grid
{
public:
	Grid(ResourceManager * manager);
	~Grid();

	void render(SDL_Renderer *renderer);

	void setTileState(int x, int y,	std::string tileStateStr);
	void moveTiles();
	int checkMiss();

private:
	const float MAP_WIDTH = 10;
	const float MAP_HEIGHT = 20;
	const float TILE_WIDTH = 38;
	const float TILE_HEIGHT = 33;

	std::vector<Tile*> m_tiles;
};
#endif

