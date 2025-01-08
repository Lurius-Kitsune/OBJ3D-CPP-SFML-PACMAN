#include "ColiderComponent.h"

ColiderComponent::ColiderComponent(Entity* _owner, const bool _isSolid) : Component(_owner)
{
	isSolid = _isSolid;
}

