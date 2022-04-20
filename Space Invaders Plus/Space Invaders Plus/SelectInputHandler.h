#ifndef SelectInputHandler_H
#define SelectInputHandler_H

#include "InputHandler.h"

class SelectInputHandler : public InputHandler
{
	void handleKeyPressed(Event& ev, RenderWindow& window) override;
	void handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window) override;
};

#endif SelectInputHandler_H