#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"


using KeyPressed = Event::KeyPressed;
using Code = Keyboard::Scancode;

class InputManager : public Singleton<InputManager>
{
	map<Code, function<void()>> callbacks;

public:

	void ConsumeInput(RenderWindow& _window);
	void BindAction(const Code& _code, const function<void()>& _callback);

private:
	void CloseWindow(RenderWindow& _window);
};