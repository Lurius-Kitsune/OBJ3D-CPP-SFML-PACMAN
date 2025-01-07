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

	const INLINE RectangleShape GetShape()const
	{
		return shape;
	}

public:
	Entity(const string& _name, const Vector2f& _shapeSize);
};