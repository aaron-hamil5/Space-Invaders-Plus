#ifndef GameOverInputHandler_H
#define GameOverInputHandler_H

#include "InputHandler.h"

class GameOverInputHandler : public InputHandler
{
public:
	void handleKeyPressed(Event& ev, RenderWindow& window) override;
	void handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window) override;
};

#endif GameOverInputHandler_H