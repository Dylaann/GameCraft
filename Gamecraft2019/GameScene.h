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
	bool m_gameStarted, m_gameOver;

<<<<<<< HEAD
	Brick * m_testbrick;
	SDL_Texture * brickTexture;
	int m_songIndex;

=======
	int m_height = 0;

	Mix_Music* m_bgm1;
	Mix_Music* m_bgm2;
	Mix_Chunk* m_click;
>>>>>>> 58cf4199c69c072d5a13b528917a6fe1bedd76a4
};