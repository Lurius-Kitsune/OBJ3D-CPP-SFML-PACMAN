#pragma once
#include "CoreMinimal.h"

class PacMan;
class Food;
class Entity;

class Level 
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	set<Food*> eatables;
	Vector2u mapSize;
	RenderWindow* window;
	int points;

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
	Level(const string& _name, RenderWindow* _window);
	~Level();

public:
	void Update();
	Entity* CheckCollision(const Vector2f& _targetPosition);
	void RemoveEatable(Food* _eatable);

private:
	void Generate();
	void SpawnEntity(const Vector2f& _shapeSize, const char _symbol, const u_int& _j, const u_int& _i);
	void PlaceEntity(const u_int& _j, const Vector2f& _shapeSize, const u_int& _i, Entity* _entity);
	void Display() const;
};