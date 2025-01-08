#include "Food.h"
#include "PacMan.h"
Food::Food(Level* _level, const string& _name, const Vector2f& _shapeSize, const FoodType& _type, const int _points)
	: Entity(_level, _name, _shapeSize, CT_OVERLAP, []() {})
{
	type = _type;
	points = _points;
}

void Food::Eat(Entity* _entity)
{
	if (type == FT_EATABLE)
	{
		if (PacMan* _pacMan = Cast<PacMan>(_entity))
		{
			_pacMan->AddPoint(points);
		}
	}
}
