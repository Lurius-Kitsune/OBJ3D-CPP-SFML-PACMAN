#pragma once
#include "CoreMinimal.h"

class PacMan;
class Ghost;
class Food;
class Entity;

struct Timer
{
	bool isRunning;
	bool isLoop;
	float duration;
	float currentTime;
	function<void()> callback;

	Timer(const float _duration, const function<void()>& _callback, const bool _isLoop = false)
	{
		isRunning = false;
		currentTime = 0.0f;
		isLoop = _isLoop;
		duration = _duration;
		callback = _callback;
	}

	void Start()
	{
		Reset();
		isRunning = true;
	}

	void Update(const float _deltaTime)
	{
		if (!isRunning) return;
		currentTime += _deltaTime;
		if (currentTime >= duration)
		{
			callback();
			isRunning = isLoop;
			Reset();
		}
	}

	void Reset()
	{
		currentTime = 0.0f;
	}
};

class Level 
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	set<Food*> eatables;
	set<Ghost*> ghosts;
	Vector2u mapSize;
	Timer* vulnerableTimer;

public:
	INLINE Vector2u GetMapSize()const
	{
		return mapSize;
	}

	INLINE bool IsOver()
	{
		return eatables.size() <= 0;
	}

public:
	Level(const string& _name);
	~Level();

public:
	void Update();
	Entity* CheckCollision(const Vector2f& _targetPosition);
	void RemoveEatable(Food* _eatable);
	void ActiveVulnerableEvent();
	void Respawn(Entity* _entity);

private:
	void Generate();
	void SpawnEntity(const Vector2f& _shapeSize, const char _symbol, const u_int& _j, const u_int& _i);
	void PlaceEntity(const u_int& _j, const Vector2f& _shapeSize, const u_int& _i, Entity* _entity);
	void Display(RenderWindow* _window) const;
	void DeactiveVulenerableEvent();
};