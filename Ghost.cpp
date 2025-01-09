#include "Ghost.h"

Ghost::Ghost(Level* _level, const Vector2f& _shapeSize)
	: Food(_level, "Ghosts/BlueGhost_Moving", _shapeSize, FT_GHOST, 1000)
{
	animation = new AnimationComponent(this, Vector2i(texture.getSize()), Vector2i(4,1), 1);
	animation->SetCurrentFrame(Vector2i(1,0));
}

Ghost::~Ghost()
{
	delete animation;
}

void Ghost::Update()
{
	animation->Update();
}
