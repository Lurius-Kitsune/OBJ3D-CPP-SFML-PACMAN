#include "AnimationComponent.h"

#include "Entity.h"

AnimationComponent::AnimationComponent(Entity* _entity, const string& _texturePath, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin, 
	const SpriteDirection& _direction) : Component(_entity)
{
	SetTexture(_texturePath, _maxAnimationStep, _textureSize, _animationBegin, _direction);
}

void AnimationComponent::Update()
{
	animationStep++;
	if (!isLooped && animationStep < maxAnimationStep)
	{
		UpdateCurrentTexture();
	}
	else if(isLooped)
	{
		animationStep %= maxAnimationStep;
		UpdateCurrentTexture();
	}
}

void AnimationComponent::PlaySingleAnimation(const string& _path, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin, const SpriteDirection& _direction, const u_int& _step)
{
	isLooped = false;
	SetTexture(_path, _maxAnimationStep, _textureSize, _animationBegin, _direction, _step);
}

void AnimationComponent::PlayLoopAnimation(const string& _path, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin, const SpriteDirection& _direction, const u_int& _step)
{
	isLooped = true;
	SetTexture(_path, _maxAnimationStep, _textureSize, _animationBegin, _direction, _step);
}


void AnimationComponent::UpdateCurrentTexture()
{
	const int _x = (spriteDirection == SD_HORIZONTAL ? (animationBegin.x + textureSize.x) * animationStep : animationBegin.x);
	const int _y = (spriteDirection == SD_VERTICAL ? (animationBegin.y + textureSize.y) * animationStep : animationBegin.y);
	owner->GetShape().setTextureRect(IntRect({_x, _y}, textureSize));
}

void AnimationComponent::SetTexture(const string& _path, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin,
	const SpriteDirection& _direction, const u_int& _step)
{
	maxAnimationStep = _maxAnimationStep;
	textureSize = _textureSize;
	spriteDirection = _direction;
	animationBegin = _animationBegin;
	TextureManager::GetInstance().InitShape(owner->GetShape(), owner->GetTexture(), _path);
	animationStep = _step;
	UpdateCurrentTexture();
}