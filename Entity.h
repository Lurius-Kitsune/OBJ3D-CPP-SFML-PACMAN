#pragma once
#include "CoreMinimal.h"
class Entity
{
	Vector2f shapeSize;
	RectangleShape shape;
	Texture texture;
	Vector2i coords;

public:
	const INLINE void SetPosition(const Vector2f& _position)
	{
		shape.setPosition(_position);
	}

	INLINE RectangleShape& GetShape()
	{
		return shape;
	}

public:
	Entity(const string& _name, const Vector2f& _shapeSize);

	virtual ~Entity() = default;
};