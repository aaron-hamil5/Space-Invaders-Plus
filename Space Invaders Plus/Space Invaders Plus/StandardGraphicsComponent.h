#ifndef StandardGraphicsComponent_H
#define StandardGraphicsComponent_H

#include "Component.h"
#include "GraphicsComponent.h"

#include <string>

using namespace sf;
using namespace std;

class Component;

class StandardGraphicsComponent : public GraphicsComponent
{
private:
	Sprite m_Sprite;
	string m_SpecificType = "standard";
public:
	string Component::getSpecificType()
	{
		return m_SpecificType;
	}

	void Component::start(GameObjectSharer* gos, GameObjects* self){}

	void draw(RenderWindow& window, shared_ptr<TransformComponent> t) override;
	void initializeGraphics(string bitmapName, Vector2f objectSize) override;
};
#endif StandardGraphicsComponent_H