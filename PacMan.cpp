#include "PacMan.h"
#include "InputManager.h"
PacMan::PacMan(Level* _level, const Vector2f& _shapeSize) : Entity(_level, "Pacman/PacMan_Moving", _shapeSize)
{
	movement = new MovementComponent(this);
	life = new LifeCoponent(this);
	animation = new AnimationComponent(this, Vector2i(texture.getSize()), Vector2i(3, 1), 1);
	animation->SetCurrentFrame({ 1,0 });

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
	animation->Update();
}

void PacMan::Death()
{
	life->RemoveLife();
	level->Respawn(this);
}

void PacMan::SetupInput()
{
	InputManager& _inputManager = InputManager::GetInstance();

	_inputManager.BindAction([&]()
	{
		movement->ToogleMoveStatus(); 
		animation->ToogleRunStatus();
		animation->SetCurrentFrame({ 1,0 });
	}, Code::Space);

	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(0, -1)); }, { Code::Z, Code::Up });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(0, 1)); }, { Code::S, Code::Down });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(-1, 0)); }, { Code::Q, Code::Left });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(1, 0)); }, { Code::D, Code::Right });
}

