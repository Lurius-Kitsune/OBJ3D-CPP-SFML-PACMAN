#include "Entity.h"
#include "TextureManager.h"
#include "ColiderComponent.h"
Entity::Entity(const string& _name, const Vector2f& _shapeSize)
{
	shapeSize = _shapeSize;
	shape = RectangleShape(shapeSize);
	shape.setOrigin(shapeSize / 2.0f);
	colliderComponent = new ColiderComponent(this);
	TextureManager::GetInstance().InitShape(shape, texture, _name);
}

Entity::~Entity()
{
	delete colliderComponent;
}
