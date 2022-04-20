#ifndef GameOverUIPanel_H
#define GameOverUIPanel_H

#include "UIPanel.h"

class GameOverUIPanel : public UIPanel
{
private:
	void initialiseButtons();
public:
	GameOverUIPanel(Vector2i res);
	void virtual draw(RenderWindow& window);
};

#endif GameOverInputHandler_H