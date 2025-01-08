#include "MovementComponent.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner) 
{
	speed = 1;
}

void MovementComponent::Update()
{
	Move();
}

void MovementComponent::Move()
{
	cout << direction.x << "->" << direction.y << endl;
	const float _x = direction.x * speed * owner->GetShapeSize().x;
	const float _y = direction.y * speed * owner->GetShapeSize().y;
	owner->GetShape().move(Vector2f(_x, _y));
}

void MovementComponent::Rotate()
{

}
