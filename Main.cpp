#include "CoreMinimal.h"
#include "Level.h"
#include "InputManager.h"
int main()
{

    Level _level = Level("SmallMap");
    RenderWindow _window(VideoMode(_level.GetMapSize()), "Pac Man");

    while (_window.isOpen())
    {
        InputManager::GetInstance().ConsumeInput(_window);

        _window.clear();
        _level.Display(_window);
        _window.display();
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
