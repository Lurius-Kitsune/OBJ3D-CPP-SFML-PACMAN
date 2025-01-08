#pragma once
#include "CoreMinimal.h"
#include "Object.h"

class Component : public Object
{
protected:
	class Entity* owner;

public:
	INLINE Entity* GetOwner() const
	{
		return owner;
	}
public:
	Component(Entity* _owner);

public:
	virtual void Update() override;
};