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

void Brick::update(int stack, int score)
{
	if (score > 10) {
		speed = 10;
	}
	if (score > 10) {
		speed = 15;
	}
	if (score > 15) {
		speed = 20;
	}
	if (score > 20) {
		speed = 30;
	}

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
		if (m_velocity.y < 8.8)
			m_velocity.y += GRAVITY;

		if (m_position.y + (33 * stack) > 667)
		{
			m_position.y = 667 - (33 * stack);
			m_velocity.x = 0;
			m_velocity.y = 0;
			m_done = true;
			//std::system("PAUSE");
		}
	}
	else {
		if (m_moveSpeed > m_moveTime) {
			if (m_moveRight) {
				moveRight();
			}
			else {
				moveLeft();
			}
			m_moveSpeed = 0;
		}

		m_moveSpeed += speed;
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

void Brick::moveLeft()
{
	if (m_position.x > 0) {
		m_position.x -= 37.5;
		m_moveRight = false;
	}
	else {
		m_moveRight = true;
	}
}

void Brick::moveRight()
{
	if (m_position.x + (m_blocksize * 37.5) < 375) {
		m_position.x += 37.5;
		m_moveRight = true;
	}
	else {
		m_moveRight = false;
	}
	
}
