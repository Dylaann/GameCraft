#include "Brick.h"


Brick::Brick(int blocksize, SDL_Texture * tex, Vector2f pos) :
	m_texture(tex),
	m_blocksize(blocksize),
	m_position(pos)
{
	//Set size of brick, width multiplied by the amount of bricks across
	m_size.x = static_cast<float>(TEXTURE_WIDTH);
	m_size.y = static_cast<float>(TEXTURE_HEIGHT);
	//Set source rect
	m_src.x = 0;
	m_src.y = 0;
	m_src.w = m_size.x;
	m_src.h = m_size.y;

	for (int i = 0; i < m_blocksize; i++)
	{
		m_dstRects.push_back(new SDL_Rect({ (int)(m_position.x + m_size.x * i), (int)(m_position.y + 10 + m_size.y), TEXTURE_WIDTH, TEXTURE_HEIGHT }));
		m_textures.push_back(m_texture);
	}
}

Brick::~Brick()
{

}

void Brick::update()
{
	//Increment position by velocity vector
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	for (int i = 0; i < m_blocksize; i++)
	{
		m_dstRects.at(i)->x = m_position.x + m_size.x * i;
		m_dstRects.at(i)->y = m_position.y + m_velocity.y;
	}

	//If block has been dropped, apply gravity
	if (m_isDropped)
	{
		//Add gravity to velocity
		if (m_velocity.y < 5)
			m_velocity.y += GRAVITY;

		if (m_position.y + 33 > 667)
		{
			m_position.y = 667 - 33;
			m_velocity.x = 0;
			m_velocity.y = 0;
			m_isDropped = false;
			//std::system("PAUSE");
		}
	}
}

void Brick::render(SDL_Renderer & renderer)
{
	//Set destination rect
	for (auto r : m_dstRects)
	{
		//SDL_RenderCopy(&renderer, m_texture, &m_src, &m_dst);
	}
	for (int i = 0; i < m_blocksize; i++)
	{
		SDL_RenderCopy(&renderer, m_textures.at(i), &m_src, m_dstRects.at(i));
	}
}