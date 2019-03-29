#pragma once
#include <map>
#include <SDL.h>
#include "GameScene.h"
#include "Menu.h"
#include "Resource Manager\ResourceManager.h"

class MenuManager
{
public:
	MenuManager();
	void update();
	void draw(SDL_Renderer& renderer);
	//void handleInput(InputSystem& input);
	void setResourceHandler(ResourceManager * resources);
	//void setSystemPtr(std::map<std::string, System*>& systems);
	void setScene(std::string scene);
	std::map<std::string, Scene*> m_scenes;
	bool getGameOver() {
		if (m_current->getStgt() == "Menu") {
			return m_current->getCheckGame();
		}
		else
		{
			return false;
		}
	}
	Scene* m_current; //Ptr to the curretn scene
private:
	
	ResourceManager* m_resources;
	bool m_over = false;
};