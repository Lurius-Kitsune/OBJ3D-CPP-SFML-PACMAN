#include "Food.h"
#include "PacMan.h"
#include "Game.h"

Food::Food(Level* _level, const string& _name, const Vector2f& _shapeSize, const FoodType& _type, const int _points)
	: Entity(_level, _name, _shapeSize, CT_OVERLAP, [&](Entity* _entity) {Eat(_entity); })
{
	type = _type;
	points = _points;
}

void Food::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = Cast<PacMan>(_entity))
	{
		Game& _game = Game::GetInstance();
		if(type == FT_EATABLE)
		{
			level->RemoveEatable(this);
		}
		else if (type == FT_APPLE)
		{
			level->ActiveVulnerableEvent();
		}
		type = FT_COUNT;
		shape.setScale(Vector2f());
		collision->SetType(CT_NONE);
		_game.AddScore(points);
	}
}
