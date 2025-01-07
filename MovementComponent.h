#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class MovementComponent : public Component
{
	int speed;

public:
	MovementComponent(Entity* _owner);
public:
	void Move(const Vector2i& _direction);
};