#pragma once
#include "CoreMinimal.h"
#include "PacMan.h"

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	Vector2u mapSize;
	RenderWindow* window;

public:
	const INLINE Vector2u GetMapSize()const
	{
		return mapSize;
	}

	const INLINE PacMan* GetPacMan()const
	{
		for (Entity* _entity : entities)
		{
			if (PacMan* _pacman = dynamic_cast<PacMan*>(_entity))
			{
				return _pacman;
			}
		}
	}
public:
	Level(const string& _name, RenderWindow* _window);
	~Level();

public:
	void Update();

private:
	void Generate();
	void SpawnEntity(const Vector2f& _shapeSize, const char _symbol, const u_int& _j, const u_int& _i);
	void PlaceEntity(const u_int& _j, const Vector2f& _shapeSize, const u_int& _i, Entity* _entity);
	void Display() const;
};