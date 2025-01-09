#include "Ghost.h"
#include "PacMan.h"
#include "InputManager.h"

Ghost::Ghost(Level* _level, const GhostData& _data, const Vector2f& _shapeSize)
	: Food(_level, _shapeSize, FT_GHOST, 1000)
{
	data = _data;
	movement = new MovementComponent(this);
	animation = new AnimationComponent(this, "Ghosts/" + _data.GetGhostName() + "Moving", 4, { 16, 16 }, { 0,0 }, SD_HORIZONTAL);
	isVulnerable = false;
	isDead = false;
	SetupInput();
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
	movement->SetDirection(_direction[RandomInt(0, 3)]);
	movement->Update();
	animation->Update();
}

void Ghost::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = Cast<PacMan>(_entity))
	{
		// On check si pacman est en mode "overpower"
		// Si oui, ont meurt et ont retourne à notre spawn point 
		// Sinon on bute pacman
		if (_pacMan->IsInvulnerable())
		{
			Food::Eat(_entity);
		}
		else
		{
			_pacMan->Die();
		}
	}
}

void Ghost::SetupInput()
{
	InputManager& _inputManager = InputManager::GetInstance();
	_inputManager.BindAction([&]() { movement->ToogleMoveStatus(); }, Code::Space);


}
