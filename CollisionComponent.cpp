#include "CollisionComponent.h"



CollisionComponent::CollisionComponent(const CollisionType& _type, const function<void(Entity* _entity)>& _callback, Entity* _owner)
	: Component(_owner)
{
	type = _type;
	callback = _callback;
}

bool CollisionComponent::Collide(Entity* _entity)
{
	if (type == CT_OVERLAP)
	{
		callback(_entity);
	}
	return type != CT_BLOCK;
}
