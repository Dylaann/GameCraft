#pragma once

class Menu
{
public: 
	Menu();
	void start();
	void stop();
	void update();
	void draw();
	void handleButtonPressed();
private:
	int m_currentIndex;


};