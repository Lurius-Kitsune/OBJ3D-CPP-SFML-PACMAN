#include "CollisionComponent.h"



CollisionComponent::CollisionComponent(const CollisionType& _type, const function<void()>& _callback, Entity* _owner)
	: Component(_owner)
{
	type = _type;
	callback = _callback;
}

bool CollisionComponent::Collide()
{
	return type != CT_BLOCK;
}
