#include "Component.h"
#include "Entity.h"

Component::Component(Entity* _owner)
{
	owner = _owner;
}

void Component::Update()
{
}
