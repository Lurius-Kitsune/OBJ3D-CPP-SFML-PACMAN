#include "CoreMinimal.h"
#include "Level.h"
int main()
{
    // THOMAS A FAIT SA!
    #pragma warning (push)
    #pragma warning (disable: 4275)
    // ====

    Level _level = Level("SmallMap");

    // Crée une fenêtre avec une taille et un titre
   // Fenetre de rendu
   // Plusieur mode de rendu
    RenderWindow _window(VideoMode(_level.GetMapSize()), "Pac Man");

    /*CircleShape _shape(100.f);
    _shape.setFillColor(Color::Green);*/

    while (_window.isOpen())
    {
        while (const std::optional _event = _window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                _window.close();
            }

            if (const Event::KeyPressed* _key = _event->getIf<Event::KeyPressed>())
            {
                if (_key->code == Keyboard::Key::Up)
                {
                    _level.GetPacMan()->GetMovementComponent()->Move({ 0,-1 });
                }

                if (_key->code == Keyboard::Key::Left)
                {
                    _level.GetPacMan()->GetMovementComponent()->Move({ -1,0 });
                }

                if (_key->code == Keyboard::Key::Right)
                {
                    _level.GetPacMan()->GetMovementComponent()->Move({ 1,0 });
                }

                if (_key->code == Keyboard::Key::Down)
                {
                    _level.GetPacMan()->GetMovementComponent()->Move({ 0,1 });
                }
            }
        }

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
* 
* 
*/
