#include "CoreMinimal.h"
#include "Level.h"
int main()
{
    Level _level = Level("SmallMap");
    // Crée une fenêtre avec une taille et un titre
   // Fenetre de rendu
   // Plusieur mode de rendu
    RenderWindow _window(VideoMode({ 200, 200 }), "Pac Man");

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
        }

        _window.clear();
        //_window.draw(_shape);
        _window.draw()
        _window.display();
    }


    return EXIT_SUCCESS;
}

// 1- Lecture de fichier .txt
// 2- Generation des Entité
// 3- Boucle affichage Entité