#include "Screen.h"

void Screen::initialise(){}
void Screen::addPanel(std::unique_ptr<UIPanel> p, ScreenManagerRemoteControl* smrc, std::shared_ptr<InputHandler> ih)
{
	ih->initInputHandler(smrc, p->getButtons(), &p->m_View, this);
	m_Panel.push_back(move(p));
	m_InputHandler.push_back(ih);
}

void Screen::handleInput(RenderWindow& window)
{
	Event e;
	auto itr = m_InputHandler.begin();
	auto end = m_InputHandler.end();
	while (window.pollEvent(e))
	{
		for (itr; itr != end; ++itr)
			(*itr)->handleInput(window, e);
	}
}

void Screen::update(float FPS){}

void Screen::draw(RenderWindow& window){
	auto itr = m_Panel.begin();
	auto end = m_Panel.end();

	for (itr; itr != end; ++itr)
	{
		//TODO: Ask about error
		(*itr)->draw(window);
	}
}

