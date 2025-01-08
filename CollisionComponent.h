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
	function<void(Entity* _entity)> callback;

public:
	CollisionComponent(const CollisionType& _type, const function<void(Entity* _entity)>& _callback , Entity * _owner);
public:
	bool Collide(Entity* _entity);
};