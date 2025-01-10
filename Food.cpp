#include "Food.h"
#include "PacMan.h"
#include "Game.h"

Food::Food(Level* _level, const string& _name, const Vector2f& _shapeSize, const EntityType& _type, const int _points)
	: Entity(_level, _name, _shapeSize, _type)
{
	points = _points;
}

bool Food::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = Cast<PacMan>(_entity))
	{
		Game& _game = Game::GetInstance();
		if(type == ET_EATBLE)
		{
			level->RemoveEatable(this);
		}
		else if (type == ET_APPLE)
		{
			level->ActiveVulnerableEvent();
		}
		else if (type == ET_GHOST)
		{
			cout << "crounch crounch, je fus mangeeeeeee" << endl;
		}

		shape.setScale(Vector2f());
		_game.AddScore(points);
	}

	return true;
}
