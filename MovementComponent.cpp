#include "MovementComponent.h"

void MovementComponent::Move(const Vector2i& _direction)
{
	owner->GetShape().move(Vector2f(_direction * speed));
}
