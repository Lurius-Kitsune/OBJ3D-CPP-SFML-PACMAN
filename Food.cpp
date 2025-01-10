#include "Food.h"
#include "PacMan.h"
#include "Game.h"

Food::Food(Level* _level, const string& _name, const Vector2f& _shapeSize, const EntityType& _type, const int _points)
	: Entity(_level, _name, _shapeSize, _type)
{
	points = _points;
}

void Food::Destroy()
{
	if (type == ET_EATBLE || type == ET_APPLE)
	{
		level->RemoveEatable(this);
	}
	shape.setScale(Vector2f());
	Super::Destroy();
}

void Food::Death(Entity* _entity)
{
	Destroy();
}
