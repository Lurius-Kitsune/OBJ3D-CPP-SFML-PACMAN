#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "MovementComponent.h"
#include "LifeComponent.h"

class PacMan : public Entity
{
	MovementComponent* movement;
	LifeCoponent* life;

public:
	PacMan(const string& _name, const Vector2f& _shapeSize);
	~PacMan();
};