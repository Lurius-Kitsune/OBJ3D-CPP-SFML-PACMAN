#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"
#include "Level.h"

#define MAP_SIZE_X 28
#define MAP_SIZE_Y 12
#define TILE_SIZE 20

enum LevelSize
{
	LS_SMALL,
	LS_CLASSIC,
	LS_BIG,

	LS_COUNT
};

class Game
{
	vector<Level*> availableLevel;
	Level* selectedLevel;
	RenderWindow windowGame;

public:
	RenderWindow& GetWindow()
	{
		return windowGame;
	}

public:
	Game();
	~Game();

public:
	void Launch();

	void Loop();
};