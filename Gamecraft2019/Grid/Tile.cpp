#include "Tile.h"

Tile::Tile(int x, int y, int w, int h, ResourceManager * manager) : m_position(x, y),
	m_rect(w, h),
	myManager(manager)
{
	m_drawRect.x = x;
	m_drawRect.y = y;
	m_drawRect.w = w;
	m_drawRect.h = h;


}

Tile::~Tile()
{
}

void Tile::render(SDL_Renderer * renderer)
{
	if (m_currentState == TileState::Empty) {
		m_currentTexture = NULL;
	}
	else if (m_currentState == TileState::Old) {
		// Whatever pic
		m_currentTexture = myManager->getImageResource("red");
	}
	else if (m_currentState == TileState::Current) {
		// Whatever pic
		m_currentTexture = myManager->getImageResource("yellow");
	}
	
	SDL_RenderCopy(renderer, m_currentTexture, NULL, &m_drawRect);
}
