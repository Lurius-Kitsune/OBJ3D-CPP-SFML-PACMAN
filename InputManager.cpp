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
            for (const InputData& _inputData : callbacks )
            {
                if (_inputData.TryToExecute(_key)) break;
            }
        }
    }
}

void InputManager::BindAction(const Code& _code, const function<void()>& _callback)
{
    callbacks.push_back(InputData(_callback, { _code }));
}

void InputManager::BindAction(const vector<Code>& _codes, const function<void()>& _callback)
{
    callbacks.push_back(InputData(_callback, _codes, _codes.empty()));
}

void InputManager::CloseWindow(RenderWindow& _window)
{
    _window.close();
}
