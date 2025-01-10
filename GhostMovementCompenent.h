#pragma once
#include "CoreMinimal.h"
#include "MovementComponent.h"

class GhostMovementCompenent : public MovementComponent
{

public:

public:
	GhostMovementCompenent(Entity* _owner);

public:
	virtual void Update() override;
	void ComputeNewDirection();
};