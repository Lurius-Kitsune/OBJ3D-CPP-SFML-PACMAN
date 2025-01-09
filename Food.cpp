#include "Food.h"
#include "PacMan.h"
Food::Food(Level* _level, const string& _name, const Vector2f& _shapeSize, const FoodType& _type, const int _points)
	: Entity(_level, _name, _shapeSize, CT_OVERLAP, [&](Entity* _entity) {Eat(_entity); })
{
	type = _type;
	points = _points;
}

Food::Food(Level* _level, const Vector2f& _shapeSize, const FoodType& _type, const int _points)
	: Entity(_level, _shapeSize, CT_OVERLAP, [&](Entity* _entity) {Eat(_entity); })
{
	type = _type;
	points = _points;
}

void Food::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = Cast<PacMan>(_entity))
	{
		_pacMan->AddPoint(points);
		if (type != FT_GHOST)
		{
			// TODO Code pour aller au spawn
			shape.setScale(Vector2f());
		}
	}
}
