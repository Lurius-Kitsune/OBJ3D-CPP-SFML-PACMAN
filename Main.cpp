#include "CoreMinimal.h"
#include "Level.h"
#include "InputManager.h"
int main()
{
    
    RenderWindow _window(VideoMode(), "Pac Man");
    Level _level = Level("SmallMap", &_window);

    while (_window.isOpen())
    {
        InputManager::GetInstance().ConsumeInput(_window);

        _window.clear();
        _level.Update();
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
