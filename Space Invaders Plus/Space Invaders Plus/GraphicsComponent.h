#ifndef GraphicsComponent_H
#define GraphicsComponent_H

#include "Component.h"
#include "TransformComponent.h"
#include "GameObjectSharer.h"

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class GraphicsComponent : public Component
{
private:
	string m_Type = "graphics";
	bool m_Enabled = false;
public:
	virtual void draw(RenderWindow& window, shared_ptr<TransformComponent> t) = 0;
	virtual void initializeGraphics(string bitmapName, Vector2f objectSize) = 0;

	string Component::getType()
	{
		return m_Type;
	}
	void Component::DisableComponent()
	{
		m_Enabled = false;
	}
	void Component::EnableComponent()
	{
		m_Enabled = true;
	}

	bool Component::enabled()
	{
		return m_Enabled;
	}

	void Component::start(GameObjectSharer* gos, GameObjects* self){}
};
#endif GraphicsComponent_H