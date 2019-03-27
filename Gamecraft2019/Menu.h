#pragma once
#include "SDL.h"
#include "../include/SDL_ttf.h"
#include "../include/SDL_image.h"
#include "Resource Manager\ResourceManager.h"
#include <iostream>
#include "Scene.h"
#include "Vector2f.h"
#include <vector>

#define TEXTURE_WIDTH 91
#define TEXTURE_HEIGHT 61

class Menu : public Scene
{
public: 
	Menu();
	void start();
	void stop();
	void update();
	void draw(SDL_Renderer& renderer);
	void handleButtonPressed();
	bool getCheckGame() { return m_gameOver; }
private:
	int m_currentIndex;
	SDL_Rect  m_rect;
	SDL_Surface * m_surface;
	SDL_Texture * m_texture;
	Vector2f m_size;
	SDL_Rect m_src;
	std::vector<SDL_Rect *> m_dstRects;
	std::vector<SDL_Rect *> m_gRects;
	std::vector<SDL_Texture*> m_textures;
	Vector2f m_position;
	Vector2f m_bluePos;
	Vector2f m_yellowPos;
	Vector2f m_greenPos;
	SDL_Color * m_selectedColor;
	SDL_Color * m_defaultColour;
//	ResourceManager * my_manager;

	TTF_Font * m_font;
	SDL_Texture * m_textRect;
	SDL_Texture * m_blueRect;
	SDL_Texture * m_yellowRect;
	SDL_Texture * m_greenRect;
	SDL_Texture * m_redRect;
	SDL_Color  * m_textColour;
	SDL_Texture * m_textTexture;

	bool flip1 = true;
	bool flip2 = false;

	std::string m_text;
	bool selected = false;
	bool m_gameOver = false;


};

