#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "MovementComponent.h"

class Ghost : public Entity
{
	MovementComponent* movement;

public:
	INLINE MovementComponent* GetMovementComponent()const
	{
		return movement;
	}

public:
	Ghost(const string& _name, const Vector2f& _shapeSize, const u_int& _zOffset);
	~Ghost();

private:
	void SetupInput();

};