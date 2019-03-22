#ifndef BRICK_H
#define BRICK_H

#include "SDL.h"
#include "Vector2f.h"
#include <vector>

#define TEXTURE_WIDTH 38
#define TEXTURE_HEIGHT 33
#define GRAVITY 2.1

class Brick
{
public:
	Brick(int, SDL_Texture *, Vector2f);
	~Brick();

	void update();
	void render(SDL_Renderer & renderer);

	//Getters
	Vector2f getPosition() { return m_position; }
	Vector2f getVelocity() { return m_position; }
	Vector2f getSize() { return m_size; }
	bool isDropped() { return m_isDropped; }

	//Setters
	void setDropped(bool value) { m_isDropped = value; }
private:
	SDL_Texture * m_texture;
	SDL_Surface m_surface;
	SDL_Rect m_src;
	std::vector<SDL_Rect *> m_dstRects;
	std::vector<SDL_Texture*> m_textures;
	Vector2f m_position;
	Vector2f m_velocity;
	Vector2f m_size;
	int m_blocksize;
	bool m_isDropped = false;
};

#endif
