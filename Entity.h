#pragma once
#include "CoreMinimal.h"
#include "Object.h"
#include "Level.h"
#include "CollisionComponent.h"

class Entity : public Object
{

	Vector2f shapeSize;
	RectangleShape shape;
	Texture texture;
	CollisionComponent* collision;

protected:
	Level* level;

public:
	INLINE Level* GetLevel()const
	{
		return level;
	}

	INLINE void SetPosition(const Vector2f& _position)
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

	INLINE Vector2f GetPosition() const
	{
		return shape.getPosition();
	}

	INLINE CollisionComponent* GetCollision() const
	{
		return collision;
	}

public:
	Entity(Level* _level, const string& _name, const Vector2f& _shapeSize,
		const CollisionType& _type = CT_BLOCK, const function<void()>& _callback = {});

	virtual ~Entity();

public:
	virtual void Update() override;
};