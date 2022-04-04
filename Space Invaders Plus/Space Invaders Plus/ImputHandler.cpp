#include "InputHandler.h"
#include <sstream>

using namespace sf;

void InputHandler::initInputHandler(ScreenManagerRemoteControl* sw, std::vector<std::shared_ptr<Button>> buttons, View* pointerToUIView, Screen* parentScreen)
{
	m_ScreenManagerRemoteControl = sw;
	m_Buttons = buttons;
	m_PointerToUIPanelView = pointerToUIView;
	m_ParentScreen = parentScreen;
}
 void InputHandler::handleInput(RenderWindow& window, Event& ev)
 {
	 if (ev.type == Event::KeyPressed)
		 handleKeyPressed(ev, window);
	 if (ev.type == Event::KeyReleased)
		 handleKeyReleased(ev, window);
	if (ev.type == Event::MouseButtonReleased)
	{
		auto end = m_Buttons.end();
		for (auto i = m_Buttons.begin(); i != end; ++i)
		{
			if ((*i)->m_Collider.contains(window.mapPixelToCoords(Mouse::getPosition(), (*getPointerToUIView()))))
			{
				handleLeftClick((*i)->m_Text, window);
				break;
			}
		}
	}

	handleGamepad();
 }

void InputHandler::handleGamepad(){}
void InputHandler::handleKeyPressed(Event& ev, RenderWindow& window){}
void InputHandler::handleKeyReleased(Event& ev, RenderWindow& window) {}
void InputHandler::handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window){}

View* InputHandler::getPointerToUIView()
{
	return m_PointerToUIPanelView;
}

ScreenManagerRemoteControl* InputHandler::getPointerToScreenManagerRemoteControl()
{
	return m_ScreenManagerRemoteControl;
}

Screen* InputHandler::getParentScreen()
{
	return m_ParentScreen;
}