#include "Menu.h"

Menu::Menu(SDL_Texture * t, std::string s, SDL_Color * c1, SDL_Color * c2, ResourceManager * manager):
	m_currentIndex(0),
	m_texture(t),
	m_text(s),
	m_selectedColor(c1),
	m_defaultColour(c2),
	my_manager(manager)
{

}

void Menu::start()
{
	
	m_rect.x = 100;
	m_rect.y = 100;
	m_rect.w = 100;
	m_rect.h = 50;

	m_textRect = my_manager->getImageResource("GreenBlock");
	const char * path = "ASSETS/FONTS/arial.ttf";
	m_font = TTF_OpenFont(path, 32);
}

void Menu::stop()
{

}

void Menu::update(double dt)
{

}

void Menu::draw(SDL_Renderer & renderer)
{
	SDL_RenderClear(&renderer);
	SDL_SetRenderDrawColor(&renderer, m_defaultColour->r, m_defaultColour->g,
		m_defaultColour->b, m_defaultColour->a);

	m_surface = TTF_RenderText_Solid(m_font, m_text.c_str(), *m_textColour);
	m_textTexture = SDL_CreateTextureFromSurface(&renderer, m_surface);

	SDL_RenderCopy(&renderer, m_textRect, NULL, &m_rect);

	SDL_RenderPresent(&renderer);

	SDL_FreeSurface(m_surface);
	SDL_DestroyTexture(m_textTexture);
}
