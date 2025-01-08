#pragma once
#include "CoreMinimal.h"
#include "Level.h"
#include "Singleton.h"

class ColiderManager : public Singleton<ColiderManager>
{
	Level* selectedLevel;

public:
	void SetSelectedLevel(Level* _level)
	{
		selectedLevel = _level;
	}
};