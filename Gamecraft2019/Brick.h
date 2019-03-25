#ifndef BRICK_H
#define BRICK_H

#include "SDL.h"
#include "Vector2f.h"
#include <vector>

#define TEXTURE_WIDTH 38
#define TEXTURE_HEIGHT 33
#define GRAVITY 4.2

class Brick
{
public:
	Brick(int, SDL_Texture *, Vector2f);
	~Brick();

	void update(int stack, int score);
	void render(SDL_Renderer & renderer);

	//Getters
	Vector2f getPosition() { return m_position; }
	Vector2f getVelocity() { return m_position; }
	Vector2f getSize() { return m_size; }
	bool isDropped() { return m_isDropped; }
	int getBlockSize() { return m_blocksize; }
	bool getDone() { return m_done; }

	//Setters
	void setDropped(bool value) { m_isDropped = value; }
	void moveLeft();
	void moveRight();
	void setDone(bool setDone) { m_done = setDone; }
	void setBlockSize(int size) { m_blocksize = size; }

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
	bool spawn = false;
	bool m_isDropped = false;
	bool m_done = false;
	bool m_moveRight = true;

	int m_moveTime = 60;
	int m_moveSpeed = 0;
	int speed = 5;
};

#endif
