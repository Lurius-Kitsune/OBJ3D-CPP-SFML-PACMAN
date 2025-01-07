#pragma once
#include "Singleton.h"

class FileLoader : public Singleton<FileLoader>
{
public:

	void Test()
	{
		cout << "je suis un singleton" << endl;
	}
};