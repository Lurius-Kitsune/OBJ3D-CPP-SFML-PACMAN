#include "Game.h"
#include "InputManager.h"
Game::Game()
{
	availableLevel =
	{
		new Level("SmallMap"),
		new Level("ClassicMap"),
		new Level("BigMap")
	};
	selectedLevel = availableLevel[0];
}

Game::~Game()
{
	for (Level* _level : availableLevel)
	{
		delete _level;
	}
}

void Game::Launch()
{
	windowGame = RenderWindow(VideoMode(selectedLevel->GetMapSize()), "Pac Man");

	while (windowGame.isOpen())
	{
		InputManager::GetInstance().ConsumeInput(windowGame);

		windowGame.clear();
		selectedLevel->Display(windowGame);
		windowGame.display();
	}
}
