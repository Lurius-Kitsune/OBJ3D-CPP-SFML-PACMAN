#include "Game.h"
#include "InputManager.h"

Game::Game()
{
	availableLevel =
	{
		new Level("SmallMap", &windowGame),
		new Level("ClassicMap",&windowGame),
		new Level("BigMap",&windowGame)
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
	windowGame = RenderWindow(VideoMode(Vector2u(MAP_SIZE_X * TILE_SIZE, MAP_SIZE_Y * TILE_SIZE)), "Pac Man");
	Loop();
}

void Game::Loop()
{
	while (windowGame.isOpen())
	{
		InputManager::GetInstance().ConsumeInput(windowGame);

		windowGame.clear();
		selectedLevel->Update();
		windowGame.display();
		SLEEP(250ms);
	}
}
