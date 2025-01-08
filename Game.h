#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"
#include "Level.h"

enum LevelSize
{
	LS_SMALL,
	LS_CLASSIC,
	LS_BIG,

	LS_COUNT
};

class Game : public Singleton<Game>
{
	vector<Level*> availableLevel;
	Level* selectedLevel;
	RenderWindow windowGame;

public:
	Game();
	~Game();

public:
	void Launch();
};