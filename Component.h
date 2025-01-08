#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
class Component : public Object
{
protected:
	Entity* owner;

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