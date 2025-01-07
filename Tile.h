#pragma once
#include "CoreMinimal.h"
class Tile
{
	Vector2f coordinate;
	RectangleShape shape;
	Texture texture;

public:
	RectangleShape& GetShape() 
	{
		return shape;
	}

public:

	Tile() = default;

	Tile(const Vector2f& _cordinates, const RectangleShape& _shape, const Texture& _texture);
};

