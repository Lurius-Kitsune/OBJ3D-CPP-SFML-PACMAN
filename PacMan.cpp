#include "PacMan.h"

PacMan::PacMan(const string& _name, const Vector2f& _shapeSize) : Entity(_name, _shapeSize)
{
	movement = new MovementComponent(this);
	life = new LifeCoponent(this);
}

PacMan::~PacMan()
{
	delete movement;
	delete life;
}
