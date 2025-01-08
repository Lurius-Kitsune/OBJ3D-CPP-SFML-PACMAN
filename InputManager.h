#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"


using KeyPressed = Event::KeyPressed;
using Code = Keyboard::Key;


struct InputData
{
	vector<Code> codes;
	bool isAnyKey;


	InputData(const vector<Code>& _codes, const bool _isAnyKey)
	{
		codes = _codes;
		isAnyKey = _isAnyKey;
	}
};

class InputManager : public Singleton<InputManager>
{
	map<Code, > callbacks;

public:

	void ConsumeInput(RenderWindow& _window);
	void BindAction(const Code& _code, const function<void()>& _callback);

private:
	void CloseWindow(RenderWindow& _window);
};