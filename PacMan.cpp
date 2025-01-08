#include "PacMan.h"
#include "InputManager.h"
PacMan::PacMan(const string& _name, const Vector2f& _shapeSize, const u_int& _zOffset) : Entity(_name, _shapeSize, _zOffset)
{
	movement = new MovementComponent(this);
	life = new LifeCoponent(this);
	GetShape().setOrigin(_shapeSize / 2.0F);
	SetupInput();
}

PacMan::~PacMan()
{
	delete movement;
	delete life;
}

void PacMan::SetupInput()
{
	InputManager& _inputManager = InputManager::GetInstance();
	_inputManager.BindAction(Code::Z, [&](){ movement->Move(Vector2i(0,-1)); });
	_inputManager.BindAction(Code::S, [&](){ movement->Move(Vector2i(0, 1)); });
	_inputManager.BindAction(Code::Q, [&](){ movement->Move(Vector2i(-1, 0)); });
	_inputManager.BindAction(Code::D, [&](){ movement->Move(Vector2i(1, 0)); });
}

