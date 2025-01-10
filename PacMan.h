#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "MovementComponent.h"
#include "LifeComponent.h"
#include "AnimationComponent.h"
#include "TextureManager.h"

class PacMan : public Entity
{
	MovementComponent* movement;
	LifeCoponent* life;
	AnimationComponent* animation;
	int deathSpriteNumber;
	bool isDead;

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
	void Death();

	void DisplayDeath();
private:
	void SetupInput();
	void EatGhost(Entity* _entity);
	void EatEatable(Entity* _entity);
	void EatApple(Entity* _entity);
	void RetrieveScore(Food* _entity);

};