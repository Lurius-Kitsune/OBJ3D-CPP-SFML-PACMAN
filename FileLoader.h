#pragma once
#include "Singleton.h"
#include "CoreMinimal.h"

class FileLoader : public Singleton<FileLoader>
{
public:
	vector<string> ReadAll(const char* _path)const;
};