#include "AnimationComponent.h"

#include "Entity.h"

AnimationComponent::AnimationComponent(Entity* _entity, const string& _texturePath, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin, 
	const SpriteDirection& _direction) : Component(_entity)
{
	SetTexture(_texturePath, _maxAnimationStep, _textureSize, _animationBegin, _direction);
}

void AnimationComponent::NextStep()
{
	animationStep++;
	animationStep %= maxAnimationStep;
	UpdateCurrentTexture();
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

void AnimationComponent::UpdateCurrentTexture()
{
	const int _x = (spriteDirection == SD_HORIZONTAL ? (animationBegin.x + textureSize.x) * animationStep : animationBegin.x);
	const int _y = (spriteDirection == SD_VERTICAL ? (animationBegin.y + textureSize.y) * animationStep : animationBegin.y);
	owner->GetShape().setTextureRect(IntRect({_x, _y}, textureSize));
}
