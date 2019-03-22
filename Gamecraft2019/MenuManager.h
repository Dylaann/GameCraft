#pragma once
#include <map>
#include <SDL.h>
#include "GameScene.h"
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
private:
	Scene* m_current; //Ptr to the curretn scene
	ResourceManager* m_resources;
};