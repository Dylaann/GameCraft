#pragma once
#include "Scene.h"
#include "Grid\Grid.h"
#include "Brick.h"
#include "AudioComponent.h"
#include "BrickGen.h"
#include <vector>
#include <SDL_ttf.h>
#include "LeaderBoard/LeaderBoard.h"
#include <queue>
#include <mutex>
#include <condition_variable>

class GameScene : public Scene
{
public:
	GameScene();
	void start();
	//void setupUi();
	void stop();
	void update();
	bool getCheckGame() { return false; }

	void draw(SDL_Renderer& renderer);

	int produced = 0;
	int consumed = 0;
	std::mutex mx;
	std::condition_variable cv;
	std::deque<Brick*> m_q1;
	std::deque<Brick*> m_q2;
	std::deque<Brick*> m_q3;
	bool used = false;

	Brick * m_currentbrick = nullptr;
	SDL_Texture * brickTexture;
	int m_currentBrickLen = 3;

	std::thread consumerThread;
	std::thread producerThread;


	//void handleInput(InputSystem& input);
private:
	BrickGen m_generator;

	bool m_gameStarted, m_gameOver;

	int m_songIndex;
	int m_height = 0;
	Grid * m_grid;

	SDL_Texture* m_BG1;
	SDL_Texture* m_BG2;
	SDL_Rect m_BG1rect;
	SDL_Rect m_BG2rect;

	Mix_Music* m_bgm1;
	Mix_Music* m_bgm2;
	Mix_Chunk* m_click;
	bool songChanged = false;
	int m_stack = 1;
	int m_score = 0;
	std::vector<Brick*> m_bricks;

	TTF_Font* Arial;
	SDL_Texture* m_message;
	SDL_Rect m_message_rect;
	SDL_Surface* surfaceMessage;
	SDL_Color m_scoreCol = { 255, 255, 255, 255 };

	LeaderBoard * m_leaderboard;
	bool threadsMade = false;
};