#include "Entity.h"
#include "TextureManager.h"

Entity::Entity(Level* _level, const string& _name, const Vector2f& _shapeSize,
	const CollisionType& _type, const function<void(Entity* _entity)>& _callback)
{
	level = _level;
	shapeSize = _shapeSize;
	shape = RectangleShape(shapeSize);
	shape.setOrigin(_shapeSize / 2.0f);
	TextureManager::GetInstance().InitShape(shape, texture, _name);
	collision = new CollisionComponent(_type, _callback, this);
}

Entity::~Entity()
{
	delete collision;
}

void Entity::Update()
{
	collision->Update();
}
