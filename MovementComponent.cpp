#include "MovementComponent.h"
#include "Entity.h"
#include "Ghost.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner) 
{
	canMove = false;
	speed = 1;
	direction = Vector2i(1, 0);
}

void MovementComponent::Update()
{
	Move();
}

void MovementComponent::Move()
{
	if (canMove)
	{
		const float _x = direction.x * speed * owner->GetShapeSize().x;
		const float _y = direction.y * speed * owner->GetShapeSize().y;

		RectangleShape& _shape = owner->GetShape();
		const Vector2f& _destination = owner->GetShape().getPosition() + Vector2f(_x, _y);
		Entity* _entity = owner->GetLevel()->CheckCollision(_destination);

		owner->GetCollision()->Collide(_entity);
		_entity->GetCollision()->Collide(owner);
		if (!_entity || _entity->GetCollision()->IsBlocking())
		{
			_shape .setPosition(_destination);
		}
	}
}

void MovementComponent::Rotate(const Vector2i& _newDirection)
{
	RectangleShape& _shape = owner->GetShape();

	const float _angle = _newDirection.y != 0 ? 90.0f * _newDirection.y :
		_newDirection.x < 0 ? 180.0f : 0.0f;
	_shape.setRotation(degrees(_angle));
}
