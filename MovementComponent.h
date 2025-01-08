#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class MovementComponent : public Component
{
	bool canMove;
	int speed;
	Vector2i direction;

public:
	INLINE void ToogleMoveStatus()
	{
		canMove = !canMove;
	}

	INLINE void SetDirection(const Vector2i& _newDirection)
	{
		if (!canMove) return;
		if (_newDirection != direction)
		{
			Rotate(_newDirection);
		}
		direction = _newDirection;
	}

public:
	MovementComponent(Entity* _owner);

public:
	virtual void Update() override;

private : 
	void Move();
	void Rotate(const Vector2i& _newDirection);

};