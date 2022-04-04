#include "SelectScreen.h"
#include "SelectUIPanel.h"
#include "SelectInputHandler.h"

SelectScreen::SelectScreen(ScreenManagerRemoteControl* smrc, Vector2i res)
{
	auto suip = std::make_unique<SelectUIPanel>(res);
	auto sih = std::make_shared<SelectUIPanel>();

	addPanel(move:(suip), smrc, sih);
	m_ScreenManagerRemoteControl = smrc;
	m_BG_Texture.loadFromFile("assets/graphics/background.png");
	m_BG_Sprite.setTexture(m_BG_Texture);
	auto TextureSize = m_BG_Sprite.getTexture()->getSize();
	m_BG_Sprite.setScale(float(m_View.getSize().x) / TextureSize.x, float(m_View.getSize().y) / TextureSize.y);

}

void SelectScreen::draw(RenderWindow& window)
{
	window.setView(m_View);
	window.draw(m_BG_Sprite);
	Screen::draw(window);
}
