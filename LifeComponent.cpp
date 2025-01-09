#include "LifeComponent.h"
#include "Entity.h"
#include "Game.h"

LifeCoponent::LifeCoponent(Entity* _owner) : Component(_owner)
{
	ResetLife();
}

void LifeCoponent::RemoveLife()
{
	lifePoint--;
	if (lifePoint <= 0)
	{
		Game::GetInstance().Stop();
	}
}

void LifeCoponent::ResetLife()
{
	lifePoint = 3;
}
