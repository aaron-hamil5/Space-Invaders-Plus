#include "GameOverInputHandler.h"
#include "SoundEngine.h"
#include "WorldState.h"

#include <iostream>

void GameOverInputHandler::handleKeyPressed(Event& ev, RenderWindow& window)
{
	if (ev.key.code == Keyboard::Escape)
	{
		SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->SwitchScreen("Select");
	}
}

void GameOverInputHandler::handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window)
{
	if (buttonInteractedWith == "Play")
	{
		SoundEngine::playClick();
		WorldState::WAVE_NUMBER = 0;
		getPointerToScreenManagerRemoteControl()->SwitchScreen("level1");
	}
	else if (buttonInteractedWith == "Home")
	{
		SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->SwitchScreen("Select");
	}
}