#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include <iostream>
#include <list>
#include <string.h>
#include "..//Resource Manager/ResourceManager.h"

class Tile
{
public:
	enum TileState {
		Empty,
		CurrentTile,
		OldTile
	};

	Tile(int x, int y, int w, int h, ResourceManager * manager);
	~Tile();

	void render(SDL_Renderer *renderer);
	std::pair<float, float> getPos() { return m_position; }
	TileState getState() { return m_currentState; }
	void setState(std::string newState);

	std::pair<float, float> m_id;
private:
	SDL_Surface * surface;
	SDL_Rect m_drawRect;
	SDL_Texture * m_currentTexture;

	std::pair<float, float> m_position;
	std::pair<float, float> m_rect;

	TileState m_currentState = OldTile;

	ResourceManager * myManager;
};
#endif
