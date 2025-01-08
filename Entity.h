#pragma once
#include "CoreMinimal.h"
#include "Object.h"
class Entity : public Object
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

	INLINE Vector2f GetShapeSize() const
	{
		return shapeSize;
	}

public:
	Entity(const string& _name, const Vector2f& _shapeSize);

	virtual ~Entity() = default;

public:
	virtual void Update() override;
};