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
	function<bool(Entity* _entity)> callback;

public:
	INLINE void SetType(const CollisionType& _status)
	{
		type = _status;
	}
public:
	CollisionComponent(const CollisionType& _type, const function<bool(Entity* _entity)>& _callback , Entity * _owner);
public:
	bool Collide(Entity* _entity);
};