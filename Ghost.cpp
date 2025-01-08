#include "Ghost.h"
#include "InputManager.h"
Ghost::Ghost(const string& _name, const Vector2f& _shapeSize, const u_int& _zOffset) : Entity(_name, _shapeSize, _zOffset, false)
{
	movement = new MovementComponent(this);
}

Ghost::~Ghost()
{
	delete movement;
}

