#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"
#include "Level.h"

class Game : public Singleton<Game>
{
	Level* level;
	RenderWindow* window;
	int score;

public:
	INLINE void AddScore(const int _score)
	{
		score += _score;
	}
public:
	Game();
	~Game();

public:
	void Launch();

private:
	void GameLoop();
};