#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "MovementComponent.h"
#include "LifeComponent.h"
#include "AnimationComponent.h"

class PacMan : public Entity
{
	MovementComponent* movement;
	LifeCoponent* life;
	AnimationComponent* animation;
public:
	INLINE MovementComponent* GetMovementComponent()const
	{
		return movement;
	}

	INLINE LifeCoponent* GetLifeCoponent()const
	{
		return life;
	}

	INLINE AnimationComponent* GetAnimationComponent()const
	{
		return animation;
	}

public:
	PacMan(Level* _level, const Vector2f& _shapeSize);
	~PacMan();

public:
	virtual void Update() override;
private:
	void SetupInput();

};