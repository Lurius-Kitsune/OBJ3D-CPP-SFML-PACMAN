#include "PacMan.h"
#include "InputManager.h"
PacMan::PacMan(Level* _level, const string& _name, const Vector2f& _shapeSize) : Entity(_level, _name, _shapeSize)
{
	movement = new MovementComponent(this);
	life = new LifeCoponent(this);

	SetupInput();
}

PacMan::~PacMan()
{
	delete movement;
	delete life;
}

void PacMan::Update()
{
	movement->Update();
	life->Update();
}

void PacMan::SetupInput()
{
	InputManager& _inputManager = InputManager::GetInstance();
	_inputManager.BindAction([&](){ movement->ToogleMoveStatus(); }, Code::Space);
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(0, -1)); }, { Code::Z, Code::Up });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(0, 1)); }, { Code::S, Code::Down });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(-1, 0)); }, { Code::Q, Code::Left });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(1, 0)); }, { Code::D, Code::Right });
}

