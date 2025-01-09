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
		cout << "Score : " << score << endl;
	}

	INLINE RenderWindow* GetWindow() const
	{
		return window;
	}
public:
	Game();
	~Game();


public:
	void Launch();
	void Stop();

private:
	void Start();
	void Update();
};