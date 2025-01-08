#include "MovementComponent.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner) 
{
	speed = 20;
}

void MovementComponent::Move(const Vector2i& _direction)
{
	cout << _direction.x << "->" << _direction.y << endl;
	owner->GetShape().move(Vector2f(_direction * speed));
}
