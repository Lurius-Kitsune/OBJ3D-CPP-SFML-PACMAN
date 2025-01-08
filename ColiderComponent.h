#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class ColiderComponent : public Component
{

public:
	ColiderComponent(Entity* _owner);
public:
	void Move(const Vector2i& _direction);
};