#ifndef InputHandler_H
#define InputHandler_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"

using namespace sf;

class Screen;
class InputHandler
{
private:
	Screen* m_ParentScreen;
	std::vector<std::shared_ptr<Button>> m_Buttons;
	View* m_PointerToUIPanelView;
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;

public:
	void initInputHandler(ScreenManagerRemoteControl* sw, std::vector<std::shared_ptr<Button>>, View* pointerToUIView, Screen* parentScreen);
	void handleInput(RenderWindow& window, Event& ev);

	virtual void handleGamepad();
	virtual void handleKeyPressed(Event& ev, RenderWindow& window);
	virtual void handleKeyReleased(Event& ev, RenderWindow& window);
	virtual void handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window);

	View* getPointerToUIView();
	ScreenManagerRemoteControl* getPointerToScreenManagerRemoteControl();

	Screen* getParentScreen();
};

#endif InputHandler_H