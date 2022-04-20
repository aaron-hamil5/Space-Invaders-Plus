#ifndef GameUIPanel_H
#define GameUIPanel_h

#include "UIPanel.h"

class GameUIPanel : public UIPanel
{
public:
	GameUIPanel(Vector2i res);
	void draw(RenderWindow& window) override;
};
#endif GameUIPanel