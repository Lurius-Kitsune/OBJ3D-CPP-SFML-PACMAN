#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"

class TextureManager : public Singleton<TextureManager>
{
public:
	void InitShape(RectangleShape& _shape, Texture& _texture, const string& _name);
	void SetTextureRectOnShape(RectangleShape& _shape, const IntRect& _rect);
	void SetTextureRectOnShape(RectangleShape& _shape, const Vector2i& _position, const Vector2i& _size);
};