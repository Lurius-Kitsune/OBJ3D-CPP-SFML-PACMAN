#pragma once
#include "CoreMinimal.h"
#include "Food.h"
#include "AnimationComponent.h"
#include "GhostMovementCompenent.h"

class Ghost : public Food
{
	GhostMovementCompenent* movement;
	AnimationComponent* animation;
	bool isVulnerable;

public:
	INLINE void SetVulnerableStatus(const bool _status)
	{
		isVulnerable = _status;
	}

public:
	Ghost(Level* _level, const Vector2f& _shapeSize);
	~Ghost();


public:
	void SetupInput();
	virtual void Update() override;
private:
	virtual bool Eat(Entity* _entity) override;
};