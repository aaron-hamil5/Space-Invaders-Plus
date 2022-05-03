#ifndef ColliderComponent_H
#define ColliderComponent_H

#include "Component.h"
#include <iostream>

class ColliderComponent: public Component
{
private:
	string m_Type = "collider";
	bool m_Enabled = false;
public:
	//From Component Interface
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

	void Component::start(GameObjectSharer* gos, GameObjects* self)
	{
		
	}
};

#endif ColliderComponent_H
