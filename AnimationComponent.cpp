#include "AnimationComponent.h"
#include "Entity.h"
#include "TextureManager.h"

AnimationComponent::AnimationComponent(Entity* _owner, const Vector2i& _spriteSize, const Vector2i& _grid, const float _speed, const bool _isLoop)
	: Component(_owner)
{
	SetTexture(_spriteSize, _grid, _speed, _isLoop, "PacMan_Moving");
	shape = owner->GetShapePtr();
}

void AnimationComponent::Update()
{
	Component::Update();
	ChangeNextFrame();
}

void AnimationComponent::SetCurrentFrame(const Vector2i& _frame)
{
	currentFrame = _frame;
	TextureManager::GetInstance().SetTextureRectOnShape(*shape, ComputeFrameRect());
}

void AnimationComponent::SetTexture(const Vector2i& _spriteSize, const Vector2i& _grid, const float _speed, const bool _isLoop, const string& _texturePath)
{
	Reset();

	canRun = true;
	isLoop = _isLoop;
	speed = _speed;
	spriteSize = _spriteSize;
	grid = _grid;
	currentFrame = { 0, 0 };
}

void AnimationComponent::Reset()
{
	canRun = true;
	currentFrame = { 0, 0 };
}

IntRect AnimationComponent::ComputeFrameRect()
{
	const Vector2i& _tileSize = Vector2i(spriteSize.x / grid.x, spriteSize.y / grid.y);
	const Vector2i& _position = Vector2i((currentFrame.x - 1) * _tileSize.x, (currentFrame.y - 1) * _tileSize.y);
	return IntRect(_tileSize, _position);
}

void AnimationComponent::ChangeNextFrame()
{
	++currentFrame.x;
	if (currentFrame.x > grid.x)
	{
		if (isLoop)
		{
			currentFrame.x = 0;
		}
		else
		{
			canRun = false;
			return;
		}
	}
	TextureManager::GetInstance().SetTextureRectOnShape(*shape, ComputeFrameRect());
}
