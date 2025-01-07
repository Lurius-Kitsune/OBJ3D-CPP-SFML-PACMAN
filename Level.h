#pragma once
#include "CoreMinimal.h"
#include "Entity.h"

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;

public:

public:
	Level(const string& _name);
	~Level();
private:
	void Generate();
	void Display() const;
};