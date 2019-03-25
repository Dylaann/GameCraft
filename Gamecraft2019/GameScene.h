#pragma once
#include "Scene.h"
#include "Grid\Grid.h"
#include "Brick.h"
#include "AudioComponent.h"
#include "BrickGen.h"
#include <vector>
#include <SDL_ttf.h>

class GameScene : public Scene
{
public:
	GameScene();
	void start();
	//void setupUi();
	void stop();
	void update();

	void draw(SDL_Renderer& renderer);
	//void handleInput(InputSystem& input);
private:
	BrickGen m_generator;

	bool m_gameStarted, m_gameOver;

	Brick * m_testbrick;
	SDL_Texture * brickTexture;
	int m_songIndex;
	int m_height = 0;
	Grid * m_grid;

	Mix_Music* m_bgm1;
	Mix_Music* m_bgm2;
	Mix_Chunk* m_click;
	int m_stack = 1;
	int m_currentBrickLen = 3;
	int m_score = 0;
	std::vector<Brick*> m_bricks;

	TTF_Font* Arial;
};