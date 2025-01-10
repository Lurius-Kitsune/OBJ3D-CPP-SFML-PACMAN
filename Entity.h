#pragma once
#include "CoreMinimal.h"
#include "Object.h"
#include "Level.h"
#include "CollisionComponent.h"
#include "EntityType.h"

class Entity : public Object
{

	Vector2f shapeSize;
protected:
	EntityType type;
	CollisionComponent* collision;
	RectangleShape shape;
	Texture texture;
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
	INLINE RectangleShape* GetShapePtr()
	{
		return &shape;
	}

	INLINE Vector2f GetShapeSize() const
	{
		return shapeSize;
	}

	INLINE Vector2f GetPosition() const
	{
		return shape.getPosition();
	}

	INLINE EntityType GetType() const
	{
		return type;
	}

	INLINE CollisionComponent* GetCollision() const
	{
		return collision;
	}

public:
	Entity(Level* _level, const string& _name, const Vector2f& _shapeSize,
		const EntityType& _type, const bool _isBlocking = false);

	virtual ~Entity();

public:
	virtual void Update() override;
};