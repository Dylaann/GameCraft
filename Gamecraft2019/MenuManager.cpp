#include "MenuManager.h"

MenuManager::MenuManager() :
	m_current(nullptr)
{
	/*if (TTF_Init() < 0)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
	}*/
	//m_scenes["Main Menu"] = new MainMenuScene();
	m_scenes["Menu"] = new Menu();
	m_scenes["Game"] = new GameScene();
}

void MenuManager::update()
{
	//If the current scene is a scene
	if (nullptr != m_current)
	{
		//If there is a scene change
		if (m_current->changeScene())
		{
			//Change the current scene
			setScene(m_current->getNewScene());
			//Set the change scene boolean to false
			m_current->resetSceneChange();
		}

		m_current->update();
	}
}

void MenuManager::draw(SDL_Renderer & renderer)
{
	//If the current scene is a scene
	if (nullptr != m_current)
	{
		m_current->draw(renderer);
	}
}
void MenuManager::setResourceHandler(ResourceManager * resources)
{
	for (auto& scene : m_scenes)
	{
		scene.second->setResourceHandler(resources);
	}
}
/*
void MenuManager::handleInput(InputSystem& input)
{
	//If the current scene is a scene
	if (nullptr != m_current)
	{
		m_current->handleInput(input);
	}
}*/
/*
void MenuManager::setResourceHandler(ResourceHandler & resources)
{
	for (auto& scene : m_scenes)
	{
		scene.second->setResourceHandler(resources);
	}
}*/

void MenuManager::setScene(std::string scene)
{
	//Call stop on the currently selected scene
	if (nullptr != m_current)
	{
		m_current->stop();
	}
	//Set the current scene
	m_current = m_scenes[scene];

	//Call start on the newly selected scene
	m_current->start();
}