#include "Game.h"
#include "InputManager.h"
#define MAP_SIZE_X 28
#define MAP_SIZE_Y 12
#define TILE_SIZE 20

Game::Game()
{
    score = 0;
}

Game::~Game()
{
	delete window;
	delete level;
}

void Game::Launch()
{
    Start();
    Update();
}

void Game::Start()
{
    window = new RenderWindow(VideoMode(Vector2u(MAP_SIZE_X * TILE_SIZE, MAP_SIZE_Y * TILE_SIZE)), "Pac Man");
    level = new Level("SmallMap");
}

void Game::Update()
{

    while (window->isOpen())
    {
        InputManager::GetInstance().ConsumeInput(*window);

        window->clear();
        level->Update();
        window->display();
        SLEEP(250ms);
    }
}

void Game::Stop()
{
    window->close();
}
