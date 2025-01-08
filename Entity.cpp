#include "Entity.h"
#include "TextureManager.h"
Entity::Entity(const string& _name, const Vector2f& _shapeSize)
{
	shapeSize = _shapeSize;
	shape = RectangleShape(shapeSize);
	shape.setOrigin(shapeSize / 2.0f);
	TextureManager::GetInstance().InitShape(shape, texture, _name);
}
