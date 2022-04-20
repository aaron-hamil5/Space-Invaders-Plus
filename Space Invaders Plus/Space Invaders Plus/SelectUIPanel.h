#ifndef SelectUIPanel_H
#define SelectUIPanel_H

#include "UIPanel.h"

class SelectUIPanel : public UIPanel
{
private:
	void initialiseButtons();
public:
	SelectUIPanel(Vector2i res);
	void virtual draw(RenderWindow& window);
};

#endif SelectUIPanel_H