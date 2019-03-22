#include "BrickGen.h"

BrickGen::BrickGen()
{
	srand(time(NULL));
	m_nextBricks = vector<deque<Brick*>>(3);
}

void BrickGen::setTextures(vector<SDL_Texture*> texs)
{
	m_textures = texs;
}

void BrickGen::genBricks()
{
	for (int i = 0; i < 3; i++)
	{
		if(m_nextBricks[i].size() < maxBricksInQueue)
			m_nextBricks[i].push_back(new Brick(i, m_textures[rand()%m_textures.size()], Vector2f(50,50))); //generates bricks with random colors
	}
}

Brick* BrickGen::getNextBrick(int size)
{
	Brick* retval = m_nextBricks[size].front();
	m_nextBricks[size].pop_front();
	return retval;
}
