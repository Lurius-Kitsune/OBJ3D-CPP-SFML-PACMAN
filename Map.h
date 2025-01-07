#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"
#include "Tile.h"

class Map : public Singleton<Map>
{
	Texture texture;
	vector<vector<Tile*>> map;
	struct
	{
		u_int x;
		u_int y;
	} mapSize;

public:

public:
	Map() = default;
	~Map();
	void InitMap(const string& _filePath);
	void DisplayMap();
};

