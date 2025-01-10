#pragma once
#include "CoreMinimal.h"
#include "Component.h"
#include "EntityType.h"

enum CollisionType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK,

	CT_COUNT
};

class CollisionComponent : public Component
{
	bool isBlocking ;
	map<EntityType, function<void(Entity* _entity)>> callbacks;

public:
	INLINE bool IsBlocking() const
	{
		return isBlocking;
	}
public:
	CollisionComponent(Entity* _owner, const bool _isBlocking = false);
public:
	void Collide(Entity* _entity);;
	void AddCallback(const EntityType& _type, const function<void(Entity* _entity)>& _callback);

};