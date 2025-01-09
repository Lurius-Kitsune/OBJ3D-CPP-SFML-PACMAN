#pragma once

#include "CoreMinimal.h"
#include "Component.h"
#include "TextureManager.h"

enum SpriteDirection
{
	SD_VERTICAL,
	SD_HORIZONTAL
};

class AnimationComponent : public Component
{
	bool isLooped;
	Texture texture;
	u_int maxAnimationStep;
	u_int animationStep;
	Vector2i textureSize;
	Vector2i animationBegin;

	SpriteDirection spriteDirection;

public:

	AnimationComponent(Entity* _entity, const string& _texturePath, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin, const SpriteDirection& _direction);

public:
	virtual void Update() override;
	void PlaySingleAnimation(const string& _path, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin,
		const SpriteDirection& _direction, const u_int& _step = 0);
	void PlayLoopAnimation(const string& _path, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin,
		const SpriteDirection& _direction, const u_int& _step = 0);

private:
	void UpdateCurrentTexture();
	void SetTexture(const string& _path, const u_int& _maxAnimationStep, const Vector2i _textureSize, const Vector2i& _animationBegin,
		const SpriteDirection& _direction, const u_int& _step = 0);

};

