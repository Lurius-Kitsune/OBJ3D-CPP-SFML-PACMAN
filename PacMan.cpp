#include "PacMan.h"
#include "InputManager.h"

PacMan::PacMan(Level* _level, const Vector2f& _shapeSize) : Entity(_level, "Pacman/PacMan_Moving", _shapeSize, ET_PACMAN)
{
	movement = new MovementComponent(this);
	life = new LifeCoponent(this);
	animation = new AnimationComponent(this, Vector2i(texture.getSize()), Vector2i(3, 1), 1);
	animation->SetCurrentFrame({ 1,0 });
	deathSpriteNumber = 12;
	collision->AddCallback(ET_GHOST, bind(&PacMan::EatGhost, this, placeholders::_1));

	SetupInput();
}

PacMan::~PacMan()
{
	delete movement;
	delete life;
}

void PacMan::Update()
{
	if (!isDead)
	{
		movement->Update();
		animation->Update();
		life->Update();
	}
	else
	{
		DisplayDeath();
	}
}

void PacMan::Death()
{
	life->RemoveLife();
	TextureManager::GetInstance().ChangeShape(shape, texture, "Pacman/PacMan_Dying");
	animation->SetTexture(Vector2i(texture.getSize()), Vector2i(12, 1), 1, false, "PacMan_Dying");
	DisplayDeath();
	isDead = true;
}

void PacMan::DisplayDeath()
{
	if (deathSpriteNumber > 0)
	{
		animation->Update();
		SLEEP(200ms);
		deathSpriteNumber--;
		cout << deathSpriteNumber << endl;
	}
	else
	{
		deathSpriteNumber = 12;
		isDead = false;
		TextureManager::GetInstance().ChangeShape(shape, texture, "Pacman/PacMan_Moving");
		animation->SetTexture(Vector2i(texture.getSize()), Vector2i(3, 1), 1, false, "PacMan_Moving");
		level->Respawn(this);
	}
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

	_inputManager.BindAction([&]() { Death(); }, { Code::K });
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(0, -1)); }, { Code::Z, Code::Up });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(0, 1)); }, { Code::S, Code::Down });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(-1, 0)); }, { Code::Q, Code::Left });
	_inputManager.BindAction([&](){ movement->SetDirection(Vector2i(1, 0)); }, { Code::D, Code::Right });
}

void PacMan::EatGhost(Entity* _entity)
{
}

