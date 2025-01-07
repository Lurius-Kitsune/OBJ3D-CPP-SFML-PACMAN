#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class LifeCoponent : public Component
{
	int lifePoint;
public:
	LifeCoponent(Entity* _owner);

public:
	void RemoveLife();
	void ResetLife();
};