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

void Grid::setTileState(int x, int y, std::string tileStateStr)
{
	for (auto i : m_tiles) {
		if (i->m_id.first < x + 5 && i->m_id.first > x - 5 && i->m_id.second < y + 5 && i->m_id.second > y - 5) {
			i->setState(tileStateStr);
		}
	}
}

void Grid::moveTiles()
{
	for (std::vector<Tile*>::reverse_iterator i = m_tiles.rbegin(); i != m_tiles.rend(); ++i) {
		if ((*i)->getState() == (*i)->OldTile) {
			if ((*i)->m_id.second == 637) {
				(*i)->setState("Empty");
			}

			for (std::vector<Tile*>::reverse_iterator j = m_tiles.rbegin(); j != m_tiles.rend(); ++j) {

				if ((*j)->m_id.first == (*i)->m_id.first && (*j)->m_id.second == (*i)->m_id.second + 33) {
					(*j)->setState("OldTile");
					(*i)->setState("Empty");
				}
			}
		}
	}
}

int Grid::checkMiss()
{
	int misses = 0;
	for (std::vector<Tile*>::reverse_iterator i = m_tiles.rbegin(); i != m_tiles.rend(); ++i) {
		if ((*i)->getState() == (*i)->OldTile) {

			for (std::vector<Tile*>::reverse_iterator j = m_tiles.rbegin(); j != m_tiles.rend(); ++j) {

				if ((*j)->m_id.first == (*i)->m_id.first && (*j)->m_id.second == (*i)->m_id.second + 33 && (*j)->getState() == (*j)->Empty) {
					(*i)->setState("Empty");
					misses += 1;
				}
			}
		}
	}

	return misses;
}
