#ifndef GameInputHandler_H
#define GameInputHandler_H

#include "InputHandler.h"

class GameScreen;

class GameInputHandler : public InputHandler
{
public:
	void initialize();
	void handleGamepad() override;
	void handleKeyPressed(Event& ev, RenderWindow& window) override;
	void handleKeyReleased(Event& ev, RenderWindow& window) override;
};
#endif