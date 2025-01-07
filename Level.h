#pragma once
#include "CoreMinimal.h"
#include "Entity.h"

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;

public:
	const INLINE vector<Entity*> GetEntities() const
	{
		return entities;
	}
public:
	Level(const string& _name);
	~Level();

public:
	void Display(RenderWindow& _window) const;
private:
	void Generate();
};