#include "LifeComponent.h"
#include "Entity.h"

LifeCoponent::LifeCoponent(Entity* _owner) : Component(_owner)
{
	ResetLife();
}

void LifeCoponent::RemoveLife()
{
	lifePoint--;
	lifePoint = lifePoint < 0 ? 0 : lifePoint;
}

void LifeCoponent::ResetLife()
{
	lifePoint = 3;
}
