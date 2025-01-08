#include "MovementComponent.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner) 
{
	canMove = 0;
	speed = 1;
	direction = Vector2i(0, 1);
}

void MovementComponent::Update()
{
	Move();
}

void MovementComponent::Move()
{
	if (canMove)
	{
		cout << direction.x << "->" << direction.y << endl;
		const float _x = direction.x * speed * owner->GetShapeSize().x;
		const float _y = direction.y * speed * owner->GetShapeSize().y;
		owner->GetShape().move(Vector2f(_x, _y));
	}
}

void MovementComponent::Rotate(const Vector2i& _newDirection)
{
	RectangleShape& _shape = owner->GetShape();

	const float _angle = _newDirection.y != 0 ? 90.0f * _newDirection.y :
		_newDirection.y < 0 ? 180.0f : 0.0f;
	_shape.setRotation(degrees(_angle));
}
