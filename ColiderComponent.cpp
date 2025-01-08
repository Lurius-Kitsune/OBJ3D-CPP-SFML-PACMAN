#include "ColiderComponent.h"

ColiderComponent::ColiderComponent(Entity* _owner) : Component(_owner)
{
	// Le collider part de son centre
	collider = _owner->GetShape().getSize() / 2.0f;
}

