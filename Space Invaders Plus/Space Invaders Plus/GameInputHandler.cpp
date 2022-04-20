#include "GameInputHandler.h"
#include "SoundEngine.h";
#include "GameScreen.h"

void GameInputHandler::initialize()
{
	
}
void GameInputHandler::handleGamepad()
{
	
}

void GameInputHandler::handleKeyPressed(Event& ev, RenderWindow& window)
{
	if (ev.key.code == Keyboard::Escape)
	{
		SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->SwitchScreen("Select");
	}
}

void GameInputHandler::handleKeyReleased(Event& ev, RenderWindow& window)
{
	
}



