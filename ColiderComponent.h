#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class ColiderComponent : public Component
{
	Vector2f collider;
public:
	ColiderComponent(Entity* _owner);
public:

};