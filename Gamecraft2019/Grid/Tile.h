#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include <iostream>
#include <list>
#include "..//Resource Manager/ResourceManager.h"

class Tile
{
public:
	enum TileState {
		Empty,
		Current,
		Old
	};

	Tile(int x, int y, int w, int h, ResourceManager * manager);
	~Tile();

	void render(SDL_Renderer *renderer);
	std::pair<float, float> getPos() { return m_position; }
	TileState getState() { return m_currentState; }
private:
	SDL_Surface * surface;
	SDL_Rect m_drawRect;
	SDL_Texture * m_currentTexture;

	std::pair<float, float> m_position;
	std::pair<float, float> m_rect;

	TileState m_currentState = Current;

	SDL_Color red = { 255, 0, 0, 255 };
	SDL_Color green = { 0, 255, 0, 255 };
	SDL_Color black = { 0, 0, 0, 255 };
	SDL_Color m_colour = { 0, 0, 0, 255 };

	ResourceManager * myManager;

	SDL_Texture * m_currentTexture;
};
#endif
