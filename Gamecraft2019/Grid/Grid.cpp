#include "Grid.h"

Grid::Grid(ResourceManager * manager)
{
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			Tile *temp = new Tile(i * 37.5, 10 + (j * 33), TILE_WIDTH, TILE_HEIGHT, manager);
			m_tiles.push_back(temp);
		}
	}
}

Grid::~Grid()
{
}

void Grid::render(SDL_Renderer * renderer)
{
	for (auto i : m_tiles) {
		i->render(renderer);
	}
}
