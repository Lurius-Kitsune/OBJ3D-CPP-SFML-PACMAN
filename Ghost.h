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

	INLINE bool IsVulenerable()const
	{
		return isVulnerable;
	}
	INLINE void SetVulnerableStatus(const bool _status)
	{
		isVulnerable = _status;
	}

public:
	Ghost(Level* _level, const Vector2f& _shapeSize);
	~Ghost();


public:
	virtual void Update() override;
	virtual void Destroy() override;
private:
	void SetupInput();
	void EatPacMan(Entity* _entity);

};