#include "Entity.h"
#include "TextureManager.h"

Entity::Entity(Level* _level, const string& _name, const Vector2f& _shapeSize,
	const EntityType& _type, const bool _isBlocking )
{
	isToRemove = false;
	level = _level;
	shapeSize = _shapeSize;
	shape = RectangleShape(shapeSize);
	shape.setOrigin(_shapeSize / 2.0f);
	type = _type;
	TextureManager::GetInstance().InitShape(shape, texture, _name);
	collision = new CollisionComponent(this, _isBlocking);
}

Entity::~Entity()
{
	delete collision;
}

void Entity::Update()
{
	collision->Update();
	if (isToRemove)
	{
		Destroy();
	}
}

void Entity::Destroy()
{
	level->RemoveEntity(this);
	delete this;
}
