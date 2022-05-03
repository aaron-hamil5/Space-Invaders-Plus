#ifndef UpdateComponent_H
#define UpdateComponent_H

#include "Component.h"

class UpdateComponent : public Component
{
private:
	string m_Type = "update";
	bool m_Enabled = false;
public:
	virtual void update(float FPS) = 0;

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
#endif UpdateComponent_H