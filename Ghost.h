#pragma once
#include "CoreMinimal.h"
#include "Food.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

enum GhostColor
{
	GC_RED,
	GC_BLUE,
	GC_YELLOW,
};

struct GhostData
{
	GhostColor color;

	INLINE string GetGhostName()const
	{
		map<GhostColor, string> _ghostDatabase =
		{
			{GC_RED, "RedGhost_"},
			{GC_BLUE, "BlueGhost_"},
			{GC_YELLOW, "YellowGhost_"},
		};
		return _ghostDatabase[color];
	}

	INLINE string GetGhostColor()const
	{
		map<GhostColor, string> _ghostDatabase =
		{
			{GC_RED, "Red"},
			{GC_BLUE, "Blue"},
			{GC_YELLOW, "Yellow"},
		};
		return _ghostDatabase[color];
	}
};

class Ghost : public Food
{
	GhostData data;
	MovementComponent* movement;
	AnimationComponent* animation;
	bool isVulnerable;
	bool isDead;
public:
	Ghost(Level* _level, const GhostData& _data, const Vector2f& _shapeSize);

public:
	virtual void Update() override;
private:
	virtual void Eat(Entity* _entity);
	void SetupInput();
};