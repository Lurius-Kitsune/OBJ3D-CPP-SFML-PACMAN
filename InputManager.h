#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"


using KeyPressed = Event::KeyPressed;
using Code = Keyboard::Key;


struct InputData
{
	vector<Code> codes;
	bool isAnyKey;
	function<void()> callback;

	InputData(const function<void()>& _callback, const vector<Code>& _codes = {}, const bool _isAnyKey = false)
	{
		codes = _codes;
		isAnyKey = _isAnyKey;
		callback = _callback;
	}

	bool TryToExecute(const KeyPressed* _key) const 
	{
		if (!isAnyKey && !ContainsKey(_key->code)) return false;

		callback();

		return true;
	}

private:
	INLINE bool ContainsKey(Code _currentCode) const
	{
		for (const Code& _code : codes)
		{
			if (_currentCode == _code) return true;
		}
		return false;
	}
};

class InputManager : public Singleton<InputManager>
{
	vector<InputData> callbacks;

public:

	void ConsumeInput(RenderWindow& _window);
	void BindAction(const Code& _code, const function<void()>& _callback);
	void BindAction(const vector<Code>& _codes, const function<void()>& _callback);

private:
	void CloseWindow(RenderWindow& _window);
};