#include "Brick.h"


Brick::Brick(int blocksize, SDL_Texture * tex, Vector2f pos) :
	m_texture(tex),
	m_blocksize(blocksize),
	m_position(pos)
{
	//Set size of brick, width multiplied by the amount of bricks across
	m_size.x = static_cast<float>(TEXTURE_WIDTH) * m_blocksize;
	m_size.y = static_cast<float>(TEXTURE_HEIGHT);
	//Set source rect
	m_src.x = 0;
	m_src.y = 0;
	m_src.w = m_size.x;
	m_src.h = m_size.y;
}

Brick::~Brick()
{

}

void Brick::update()
{
	//Increment position by velocity vector
	m_position += m_velocity;

	//If block has been dropped, apply gravity
	if (m_isDropped)
	{
		//Add gravity to velocity
		m_velocity.y += GRAVITY;
	}
}

void Brick::render(SDL_Renderer & renderer)
{
	//Set destination rect
	m_dst.x = m_position.x;
	m_dst.y = m_position.y;
	m_dst.w = m_size.x;
	m_dst.h = m_size.y;

	SDL_RenderCopy(&renderer, m_texture, &m_src, &m_dst);
}