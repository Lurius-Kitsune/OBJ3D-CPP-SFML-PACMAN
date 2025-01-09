#include "PacMan.h"
#include "InputManager.h"
PacMan::PacMan(Level* _level, const Vector2f& _shapeSize) : Entity(_level, _shapeSize)
{
	movement = new MovementComponent(this);
	life = new LifeCoponent(this);
	animation = new AnimationComponent(this, "Pacman/PacMan_Moving", 3, { 16, 16 }, { 0,0 }, SD_HORIZONTAL);
	isInvulnerable = false;
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
	animation->Update();
}

void PacMan::AddPoint(const int _points)
{
	level->AddScore(_points);
}

void PacMan::Die()
{
	animation->PlaySingleAnimation("Pacman/PacMan_Dying", 11, { 16, 16 }, { 0,0 }, SD_HORIZONTAL);
	movement->ToogleMoveStatus();
}

void PacMan::SetupInput()
{
	InputManager& _inputManager = InputManager::GetInstance();
	_inputManager.BindAction([&](){ movement->ToogleMoveStatus(); }, Code::Space);
	_inputManager.BindAction([&](){ Die(); }, Code::K);
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(0, -1)); }, { Code::Z, Code::Up });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(0, 1)); }, { Code::S, Code::Down });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(-1, 0)); }, { Code::Q, Code::Left });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(1, 0)); }, { Code::D, Code::Right });
}

