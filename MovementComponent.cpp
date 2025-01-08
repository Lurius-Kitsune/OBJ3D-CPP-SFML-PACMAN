#include "MovementComponent.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner) 
{
	speed = 1;
}

void MovementComponent::Move(const Vector2i& _direction)
{
	cout << _direction.x << "->" << _direction.y << endl;
	const float _x = _direction.x * speed * owner->GetShapeSize().x;
	const float _y = _direction.y * speed * owner->GetShapeSize().y;
	owner->GetShape().move(Vector2f(_x, _y));
}

void MovementComponent::Rotate()
{

}
