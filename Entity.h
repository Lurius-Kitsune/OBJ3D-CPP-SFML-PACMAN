#pragma once
#include "CoreMinimal.h"
class Entity
{
	Vector2f shapeSize;
	RectangleShape shape;
	Texture texture;
	Vector2i coords;

public:
	Entity(const string& _name);
};