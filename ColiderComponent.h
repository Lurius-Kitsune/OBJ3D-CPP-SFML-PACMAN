#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class ColiderComponent : public Component
{
	bool isSolid;

public:
	ColiderComponent(Entity* _owner, const bool _isSolid);
public:

};