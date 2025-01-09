#include "AnimationComponent.h"
#include "Entity.h"
#include "TextureManager.h"

AnimationComponent::AnimationComponent(Entity* _owner, const Vector2i& _spriteSize, const Vector2i& _grid, const float _speed, const bool _isLoop)
	: Component(_owner)
{
	canRun = true;
	isLoop = _isLoop;
	speed = _speed;
	spriteSize = _spriteSize;
	grid = _grid;
	currentFrame = { 0, 0 };
	shape = owner->GetShapePtr();
}

void AnimationComponent::Update()
{
	Component::Update();
	ChangeNextFrame();
}

void AnimationComponent::Reset()
{
	canRun = true;
	currentFrame = { 0, 0 };
}

void AnimationComponent::ChangeNextFrame()
{
	++currentFrame.x;
	if (currentFrame.x > grid.x)
	{
		canRun = false;
		return;
	}
	const Vector2i& _tileSize = Vector2i(spriteSize.x / grid.x, spriteSize.y / grid.y);
	const Vector2i& _position = Vector2i((currentFrame.x - 1) * spriteSize.x, (currentFrame.y - 1) * spriteSize.y);
	TextureManager::GetInstance().SetTextureRectOnShape(*shape, _position , spriteSize);
}
