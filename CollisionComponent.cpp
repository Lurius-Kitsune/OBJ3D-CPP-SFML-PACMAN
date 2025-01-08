#include "CollisionComponent.h"



CollisionComponent::CollisionComponent(const CollisionType& _type, const function<void()>& _callback, Entity* _owner)
	: Component(_owner)
{

}

bool CollisionComponent::Collide()
{
	return type != CT_BLOCK;
}
