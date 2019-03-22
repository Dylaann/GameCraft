#ifndef BRICK_H
#define BRICK_H

#include "SDL.h"
#include "Vector2f.h"

class Brick
{
public:
	Brick(int, SDL_Texture *);
	~Brick();

	void update();
	void render(SDL_Renderer & renderer);

	Vector2f getPosition() { return m_position; }
	Vector2f getVelocity() { return m_position; }
	Vector2f getSize() { return m_size; }
private:
	SDL_Texture * m_texture;
	SDL_Surface * m_surface;
	SDL_Rect * m_src;
	SDL_Rect * m_dst;
	Vector2f m_position;
	Vector2f m_velocity;
	Vector2f m_size;
	int m_blocksize;
};

#endif
