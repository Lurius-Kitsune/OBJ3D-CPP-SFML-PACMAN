#pragma once
#include "CoreMinimal.h"
#include "Component.h"

enum CollisionType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK,

	CT_COUNT
};

class CollisionComponent : public Component
{
	CollisionType type;
	function<void()> callback;

public:
	CollisionComponent(const CollisionType& _type, const function<void()>& _callback , Entity * _owner);
public:
	void Collide();
};