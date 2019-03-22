#ifndef BRICK_H
#define BRICK_H

#include "SDL.h"
#include "Vector2f.h"

class Brick
{
public:
	Brick();
	~Brick();

	void update();
	void render(SDL_Renderer & renderer);
private:
	SDL_Texture * m_texture;
	SDL_Surface * m_surface;
	Vector2f m_position;
	Vector2f m_velocity;
};

#endif
