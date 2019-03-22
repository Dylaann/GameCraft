#pragma once
#include "SDL.h"
#include "../include/SDL_ttf.h"
#include "../include/SDL_image.h"
#include "Resource Manager\ResourceManager.h"
#include <iostream>
class Menu
{
public: 
	Menu(SDL_Texture* st, std::string string, SDL_Color * color, SDL_Color * color2, ResourceManager * manager);
	void start();
	void stop();
	void update(double dt);
	void draw(SDL_Renderer& renderer);
	void handleButtonPressed();
private:
	int m_currentIndex;
	SDL_Rect  m_rect;
	SDL_Surface * m_surface;
	SDL_Texture * m_texture;
	SDL_Color * m_selectedColor;
	SDL_Color * m_defaultColour;
	ResourceManager * my_manager;

	TTF_Font * m_font;
	SDL_Texture * m_textRect;
	SDL_Color  * m_textColour;
	SDL_Texture * m_textTexture;

	std::string m_text;
	bool selected = false;


};