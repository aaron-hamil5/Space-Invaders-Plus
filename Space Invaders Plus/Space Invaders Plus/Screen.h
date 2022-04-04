#ifndef Screen_H
#define Screen_H

#include <SFML/Graphics.hpp>
#include<vector>
#include "InputHandler.h"
#include "UIPanel.h"
#include "ScreenManagerRemoteControl.h"


class InputHandler;
class Screen {
private:
	std::vector<std::shared_ptr<InputHandler>> m_InputHandler;
	std::vector<std::unique_ptr<UIPanel>> m_Panel;
protected:
	void addPanel(std::unique_ptr<UIPanel> p, ScreenManagerRemoteControl* smrc, std::shared_ptr<InputHandler> ih);
public:
	virtual void initialise();
	virtual void update(float FPS);
	virtual void draw(RenderWindow& window);

	void handleInput(RenderWindow& window);

	View m_View;
};
#endif Screen_H