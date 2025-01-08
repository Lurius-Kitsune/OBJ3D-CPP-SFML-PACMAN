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

public:
	PacMan(Level* _level, const Vector2f& _shapeSize);
	~PacMan();

public:
	virtual void Update() override;
	void AddPoint(const int _points);
private:
	void SetupInput();

};