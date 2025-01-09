#pragma once
#include "CoreMinimal.h"
#include "Food.h"
#include "AnimationComponent.h"

class Ghost : public Food
{
	AnimationComponent* animation;

public:
	Ghost(Level* _level, const string& _name, const Vector2f& _shapeSize);
	~Ghost();

public:
	virtual void Update() override;
private:

};