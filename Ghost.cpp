#include "Ghost.h"
#include "LifeComponent.h"
#include "PacMan.h"

Ghost::Ghost(Level* _level, const Vector2f& _shapeSize)
	: Food(_level, "Ghosts/BlueGhost_Moving", _shapeSize, FT_GHOST, 1000)
{
	animation = new AnimationComponent(this, Vector2i(texture.getSize()), Vector2i(4,1), 1);
	animation->SetCurrentFrame(Vector2i(1,0));
	isVulnerable = false;
}

Ghost::~Ghost()
{
	delete animation;
}

void Ghost::Update()
{
	animation->Update();
}

void Ghost::Eat(Entity* _entity)
{
	if (PacMan* _pacMan = Cast<PacMan>(_entity))
	{
		if (isVulnerable)
		{
			Super::Eat(_entity);
		}
		else
		{
			_pacMan->Death();
			if (LifeCoponent* _life = _pacMan->GetLifeCoponent())
			{
				_life->RemoveLife();
			}
		}
	}
}
