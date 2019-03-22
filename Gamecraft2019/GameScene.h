#pragma once
#include "Scene.h"
#include "Brick.h"
#include "AudioComponent.h"

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
	bool m_audioCreated;
	bool m_gameStarted, m_gameOver;

	Brick * m_testbrick;
	SDL_Texture * brickTexture;
	int m_songIndex;

};