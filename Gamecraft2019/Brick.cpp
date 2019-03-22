#include "Brick.h"


Brick::Brick(int blocksize, SDL_Texture * tex) :
	m_texture(tex),
	m_blocksize(blocksize)
{
	//Set source rect
	m_src->x = 0;
	m_src->y = 0;
	m_src->w = m_size.x;
	m_src->h = m_size.y;
}

Brick::~Brick()
{

}

void Brick::update()
{

}

void Brick::render(SDL_Renderer & renderer)
{
	//Set destination rect
	m_dst->x = m_position.x;
	m_dst->y = m_position.y;
	m_dst->w = m_size.x;
	m_dst->h = m_size.y;

	SDL_RenderCopy(&renderer, m_texture, m_src, m_dst);
}