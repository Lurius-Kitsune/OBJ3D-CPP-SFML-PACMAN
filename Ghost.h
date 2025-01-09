#pragma once
#include "CoreMinimal.h"
#include "Food.h"
#include "AnimationComponent.h"

class Ghost : public Food
{
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
	virtual void Update() override;
private:

};