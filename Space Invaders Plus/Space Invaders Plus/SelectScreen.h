#ifndef SelectScreen_H
#define SelectScreen_H

#include "Screen.h"

class SelectScreen: public Screen
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	Texture m_BG_Texture;
	Sprite m_BG_Sprite;
public:
	SelectScreen(ScreenManagerRemoteControl* smrc, Vector2i res);

	virtual void draw(RenderWindow& window) override;
};
#endif SelectScreen_H