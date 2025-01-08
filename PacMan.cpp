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
	_inputManager.BindAction(Code::Space, [&](){ movement->ToogleMoveStatus(); });
	_inputManager.BindAction({ Code::Z, Code::Up }, [&]() { movement->SetDirection(Vector2i(0, -1)); });
	_inputManager.BindAction({ Code::S, Code::Down }, [&](){ movement->SetDirection(Vector2i(0, 1)); });
	_inputManager.BindAction({ Code::Q, Code::Left }, [&](){ movement->SetDirection(Vector2i(-1, 0)); });
	_inputManager.BindAction({ Code::D, Code::Right }, [&](){ movement->SetDirection(Vector2i(1, 0)); });
}

