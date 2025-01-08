#include "InputManager.h"

void InputManager::ConsumeInput(RenderWindow& _window)
{
    while (const std::optional _event = _window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            _window.close();
        }

        else if (const KeyPressed* _key = _event->getIf<KeyPressed>())
        {
            if (callbacks.contains(_key->code))
            {
                callbacks[_key->code]();
            }
        }
    }
}

void InputManager::BindAction(const Code& _code, const function<void()>& _callback)
{
    callbacks.insert({ _code, _callback });
}

void InputManager::CloseWindow(RenderWindow& _window)
{
    _window.close();
}
