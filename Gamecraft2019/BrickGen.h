#pragma once
#include "Brick.h"
#include <deque>
#include <vector>
#include <time.h>

using std::vector;
using std::deque;
class BrickGen
{
public:
	BrickGen();
	
	void setTextures(vector<SDL_Texture*> texs);
	void genBricks();//this can run in a separate thread;
	Brick* getNextBrick(int size);

private:
	int maxBricksInQueue = 10;
	vector<SDL_Texture*> m_textures;
	vector<deque<Brick*>> m_nextBricks;
	

};
