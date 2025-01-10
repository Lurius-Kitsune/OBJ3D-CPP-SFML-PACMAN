#pragma once
#include "CoreMinimal.h"
#include "Entity.h"

enum FoodType
{
	FT_EATABLE,
	FT_APPLE,
	FT_GHOST,
	
	FT_COUNT
};

class Food : public Entity
{
	int points;

public:
	INLINE int GetPoint()const
	{
		return points;
	}

public:
	Food(Level* _level, const string& _name, const Vector2f& _shapeSize, const EntityType& _type ,const int _points);
	void Death(Entity* _entity);

protected:
	virtual void Destroy() override;

private:
};