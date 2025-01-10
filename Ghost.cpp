#include "Ghost.h"
#include "LifeComponent.h"
#include "PacMan.h"
#include "InputManager.h"

Ghost::Ghost(Level* _level, const Vector2f& _shapeSize)
	: Food(_level, "Ghosts/BlueGhost_Moving", _shapeSize,ET_GHOST, 1000)
{
	isVulnerable = false;
	movement = new GhostMovementCompenent(this);
	collision->AddCallback(ET_PACMAN, bind(&Ghost::EatPacMan, this, placeholders::_1));
	animation = new AnimationComponent(this, Vector2i(texture.getSize()), Vector2i(4,1), 1);
	animation->SetCurrentFrame(Vector2i(1,0));
	SetupInput();
}

Ghost::~Ghost()
{
	delete animation;
	delete movement;
}

void Ghost::SetupInput()
{
	InputManager& _inputManager = InputManager::GetInstance();
	_inputManager.BindAction([&]() { movement->ToogleMoveStatus(); animation->ToogleRunStatus();}, Code::Space);
}

void Ghost::EatPacMan(Entity* _entity)
{
	if (isVulnerable) return;

	if (PacMan* _pacMan = Cast<PacMan>(_entity))
	{
		_pacMan->Death();
	}
}


void Ghost::Update()
{
	vector<Vector2i> _direction =
	{
		Vector2i(0, -1),
		Vector2i(0, 1),
		Vector2i(-1, 0),
		Vector2i(1, 0)
	};
	movement->SetDirection(_direction[RandomInt(0, 3)], false);
	movement->Update();
	animation->Update();
}

void Ghost::Destroy()
{
	Super::Destroy();
}
