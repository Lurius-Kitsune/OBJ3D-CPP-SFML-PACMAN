#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class ColiderComponent : public Component
{
	string name;
	Vector2f collider;
public:
	ColiderComponent(Entity* _owner, const string& _name);
public:

};