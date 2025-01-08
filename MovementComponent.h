#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class MovementComponent : public Component
{
	int speed;
	Vector2i direction;

public:
	INLINE void SetDirection(const Vector2i& _direction)
	{
		direction = _direction;
		Rotate();
	}

public:
	MovementComponent(Entity* _owner);

public:
	virtual void Update() override;

private : 
	void Move();
	void Rotate();

};