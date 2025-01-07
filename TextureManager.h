#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"

class TextureManager : public Singleton<TextureManager>
{
public:
	void InitShape(RectangleShape& _shape, Texture& _texture, const string& _name);
};