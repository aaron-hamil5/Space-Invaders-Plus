#ifndef RectColliderComponent_H
#define RectColliderComponent_H

#include "ColliderComponent.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class RectColliderComponent : ColliderComponent
{
private:
	string m_SpecificType = "rect";
	FloatRect m_Collider;
	string m_Tag = "";
public:
	RectColliderComponent(string name);
	string getColliderTag();
	void setOrMoveCollider(float x, float y, float width, float height);

	FloatRect& getColliderRectF();

	string getSpecificType()
	{
		return m_SpecificType;
	}

	void Component::start( GameObjectSharer* gos, GameObjects* self){}
};
#endif RectColliderComponent_H