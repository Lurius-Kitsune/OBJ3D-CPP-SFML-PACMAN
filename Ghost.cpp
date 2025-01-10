#include "Ghost.h"
#include "LifeComponent.h"
#include "PacMan.h"
#include "InputManager.h"

Ghost::Ghost(Level* _level, const Vector2f& _shapeSize)
	: Food(_level, "Ghosts/BlueGhost_Moving", _shapeSize,ET_GHOST, 1000)
{
	isVulnerable = false;
	movement = new GhostMovementCompenent(this);
	animation = new AnimationComponent(this, Vector2i(texture.getSize()), Vector2i(4,1), 1);
	animation->SetCurrentFrame(Vector2i(1,0));
	//collision->AddCallback(ET_WALL, [&]() { movement->ComputeNewDirection();  });
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

bool Ghost::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = Cast<PacMan>(_entity))
	{
		if (isVulnerable)
		{
			return Super::Eat(_entity);
		}
		else
		{
			_pacMan->Death();
			if (LifeCoponent* _life = _pacMan->GetLifeCoponent())
			{
				_life->RemoveLife();
			}
			return false;
		}
	}

	return true;

}
