#include "Tile.h"

Tile::Tile(int x, int y, int w, int h, ResourceManager * manager) : m_position(x, y),
	m_rect(w, h),
	myManager(manager)
{
	m_id = std::make_pair<float, float>((float)x, (float)y);

	m_drawRect.x = x;
	m_drawRect.y = y;
	m_drawRect.w = w;
	m_drawRect.h = h;

	TileState m_currentState = OldTile;

}

Tile::~Tile()
{
}

void Tile::render(SDL_Renderer * renderer)
{
	if (m_currentState == TileState::Empty) {
		m_currentTexture = NULL;
	}
	else if (m_currentState == TileState::OldTile) {
		m_currentTexture = myManager->getImageResource("red");
	}
	else if (m_currentState == TileState::CurrentTile) {
		m_currentTexture = myManager->getImageResource("yellow");
	}
	
	SDL_RenderCopy(renderer, m_currentTexture, NULL, &m_drawRect);
}

void Tile::setState(std::string newState)
{
	if (newState == "OldTile") {
		m_currentState = TileState::OldTile;
	}
	else if (newState == "CurrentTile") {
		m_currentState = TileState::CurrentTile;
	}
}
