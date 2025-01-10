#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class MovementComponent : public Component
{
	bool canMove;
	int speed;
protected:
	Vector2i direction;

public:
	INLINE void ToogleMoveStatus()
	{
		canMove = !canMove;
	}

	INLINE void SetDirection(const Vector2i& _newDirection, const bool _rotate=true)
	{
		if (!canMove) return;
		if (_newDirection != direction)
		{
			if(_rotate) Rotate(_newDirection);
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