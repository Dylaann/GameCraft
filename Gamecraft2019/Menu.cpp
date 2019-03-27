#include "Menu.h"

Menu::Menu()
{
	m_size.x = static_cast<float>(TEXTURE_WIDTH);
	m_size.y = static_cast<float>(TEXTURE_HEIGHT);
	m_position.x = 50;
	m_position.y = 100;
	m_src.x = 0;
	m_src.y = 0;
	m_src.w = m_size.x;
	m_src.h = m_size.y;

	for (int i = 0; i < 3; i++)
	{
		m_dstRects.push_back(new SDL_Rect({ (int)(m_position.x + m_size.x), (int)(m_position.y + 90 + m_size.y * i ), TEXTURE_WIDTH, TEXTURE_HEIGHT }));
		m_textures.push_back(m_texture);
	}
}


void Menu::start()
{
	
	//m_rect.x = 100;
	//m_rect.y = 100;
	//m_rect.w = 100;
	//m_rect.h = 50;
	m_bluePos = Vector2f(100, 100);
	m_yellowPos = Vector2f(100, 200);
	m_greenPos = Vector2f(100, 300);
	
	//m_textRect = my_manager->getImageResource("GreenBlock");
	m_blueRect = m_resources->getImageResource("blueButton");
	m_yellowRect = m_resources->getImageResource("yellowButton");
	m_greenRect = m_resources->getImageResource("greenButton");
	m_redRect = m_resources->getImageResource("redButton");

	//const char * path = "ASSETS/FONTS/arial.ttf";
	//m_font = TTF_OpenFont(path, 32);

	//m_texture = new SDL_Texture("Start", "ASSETS/FONTS/arial.ttf", 16, {200, 0, 0});
	
}

void Menu::stop()
{

}

void Menu::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_UP) {
				flip2 = false;
				flip1 = true;
			}

			if (event.key.keysym.sym == SDLK_DOWN) {
				flip1 = false;
				flip2 = true;
			}

			if (event.key.keysym.sym == SDLK_LEFT) {
			}

			if (event.key.keysym.sym == SDLK_RIGHT) {
			}

			if (event.key.keysym.sym == SDLK_SPACE) {
				if (flip1 == true)
				{
				goToScene("Game");
				}
				if (flip2 == true)
				{
					
				}
			}
			
		default:
			break;
		}
	}
}

void Menu::draw(SDL_Renderer & renderer)
{
	//SDL_RenderClear(&renderer);

	SDL_SetRenderDrawColor(&renderer, 140, 5, 90, 255);

	SDL_RenderClear(&renderer);

	//Draw the current scene
//	m_blueRect->draw(renderer);
//	m_yellowRect->draw(renderer);
//	m_greenRect->draw(renderer);

	
	//for (int i = 0; i < 3; i++)
	//{
		//SDL_RenderCopy(&renderer, m_textures.at(i), &m_src, m_dstRects.at(i));
		
//	}
//for (int i = 0; i < 3; i++)
//{
	if (flip1 == true)
	{
		SDL_RenderCopy(&renderer, m_redRect, &m_src, m_dstRects.at(1));
	}
	if (flip2 == true)
	{
		SDL_RenderCopy(&renderer, m_redRect, &m_src, m_dstRects.at(2));

	}
	
	SDL_RenderCopy(&renderer, m_blueRect, &m_src, m_dstRects.at(1));
	SDL_RenderCopy(&renderer, m_yellowRect, &m_src, m_dstRects.at(2));
	SDL_RenderCopy(&renderer, m_greenRect, &m_src, m_dstRects.at(0));

	SDL_RenderPresent(&renderer);
}
