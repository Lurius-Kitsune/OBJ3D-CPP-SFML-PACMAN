#pragma once
#include "CoreMinimal.h"

class ColiderComponent;

class Entity
{
	u_int zOffset;
	Vector2f shapeSize;
	RectangleShape shape;
	Texture texture;
	Vector2i coords;
	ColiderComponent* colliderComponent;

public:
	INLINE void SetPosition(const Vector2f& _position)
	{
		shape.setPosition(_position + shapeSize / 2.0f);
	}

	INLINE RectangleShape& GetShape()
	{
		return shape;
	}

	INLINE Vector2f GetShapeSize()const
	{
		return shapeSize;
	}


	INLINE u_int GetOffset()const
	{
		return zOffset;
	}

public:
	Entity(const string& _name, const Vector2f& _shapeSize, const u_int& _zOffset);

	virtual ~Entity();
};