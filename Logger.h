#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"

struct Logger : public Singleton<Logger>
{
	void Info(const string& _content)
	{
		cout << _content << endl;
	}

	void Error(const string& _content)
	{
		cout << "[Error]" << _content << endl;
	}
};