#include "Ghost.h"

Ghost::Ghost(Level* _level, const string& _name, const Vector2f& _shapeSize)
	: Food(_level, _name, _shapeSize, FT_GHOST,1000)
{
	animation = new AnimationComponent();
}

Ghost::~Ghost()
{
	delete animation;
}

void Ghost::Update()
{
	animation->Update();
}
