#pragma once
#include "CoreMinimal.h"
#include "Component.h"

class AnimationComponent : public Component
{
	bool canRun;
	// speed 
	float speed;
	// isLoop
	bool isLoop;

	// taille X, Y
	Vector2i spriteSize;
	Vector2i grid;

	// current frame
	Vector2i currentFrame;
	// pointeur temporaire (Optimisation)
	// Il evite de faire que de full get
	RectangleShape* shape;

public:
	INLINE void ToogleRunStatus()
	{
		canRun = !canRun;
	}

	INLINE void SetCurrentRow(const int _rowIndex)
	{
		grid.y = _rowIndex;
	}
public:
	AnimationComponent(Entity* _owner, const Vector2i& _spriteSize,
		const Vector2i& _grid, const float _speed, const bool _isLoop = true);

public:
	virtual void Update() override;
	void SetCurrentFrame(const Vector2i& _frame);
private:
	void Reset();
	IntRect ComputeFrameRect();
	void ChangeNextFrame();
};