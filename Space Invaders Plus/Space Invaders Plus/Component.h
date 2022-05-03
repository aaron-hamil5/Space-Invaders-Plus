#ifndef Component_H
#define Component_H

#include "GameObjectSharer.h"
#include <string>

using namespace std;

class GameObjects;

class Component
{
public:
	virtual string getType() = 0;
	virtual string getSpecificType() = 0;
	virtual void DisableComponent() = 0;
	virtual void EnableComponent() = 0;
	virtual bool enabled() = 0;
	virtual void start(GameObjectSharer* gos, GameObjects* self) = 0;
};
#endif Component_H