#include "Entity.h"
#include "TextureManager.h"
Entity::Entity(const string& _name)
{
	shapeSize = Vector2f(20.0f, 20.0f);
	shape = RectangleShape(shapeSize);
	TextureManager::GetInstance().InitShape(shape, texture, _name);
}
