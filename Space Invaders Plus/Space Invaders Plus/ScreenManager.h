#ifndef ScreenManager_H
#define ScreenManager_H

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

#include "ScreenManagerRemoteControl.h"
#include "LevelManager.h"
#include "BitmapStore.h"

using namespace sf;

class ScreenManager : public ScreenManagerRemoteControl {
private:
	std::map <std::string, unique_ptr<Screen>> m_Screens;
	LevelManager m_LevelManager;
protected:
	std::string m_CurrentScreen = "Select";
public:
	BitmapStore m_BS;
	ScreenManager(Vector2i res);

	void handleInput(RenderWindow& window);
	void update(float FPS);
	void draw(RenderWindow& window);

	//TODO (1): Code continues after defining ScreenManagerRemoteControl class
	// level Manager and gameSharer Classes
};

#endif ScreenManager_H