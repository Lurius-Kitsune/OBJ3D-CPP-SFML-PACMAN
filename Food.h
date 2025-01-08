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
	FoodType type;
public:
	Food(Level* _level, const string& _name, const Vector2f& _shapeSize, const FoodType& _type ,const int _points);

private:
	void Eat(Entity* _entity);
};