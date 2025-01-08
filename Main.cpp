#include "CoreMinimal.h"
#include "Level.h"
#include "InputManager.h"

#define MAP_SIZE_X 28
#define MAP_SIZE_Y 12
#define TILE_SIZE 20

int main()
{
    
    RenderWindow _window(VideoMode(Vector2u(MAP_SIZE_X * TILE_SIZE, MAP_SIZE_Y * TILE_SIZE)), "Pac Man");
    Level _level = Level("SmallMap", &_window);

    while (_window.isOpen())
    {
        InputManager::GetInstance().ConsumeInput(_window);

        _window.clear();
        _level.Update();
        _window.display();
        SLEEP(500ms);
    }
    return EXIT_SUCCESS;
}

/*
*
* // 1- Lecture de fichier .txt
  // 2- Generation des Entité
  // 3- Boucle affichage Entité
* --
* Jeux:
* - Input Manager
*
* ----
* Collider :
* 1. SpawnEntity prend les
*
*
*/
