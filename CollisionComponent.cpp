#include "CollisionComponent.h"
#include "Entity.h"


CollisionComponent::CollisionComponent(Entity* _owner, const bool _isBlocking)
	: Component(_owner)
{
	isBlocking = _isBlocking;
	callbacks = map<EntityType, function<void(Entity* _entity)>>();
}

void CollisionComponent::Collide(Entity* _entity)
{
	/* [NOTE A NE PAS SUP]C'est mauvais cas ont doit appeller avec qui ont collide,
	* Seul ce qui bouge nous interesse.
	* Exemple : Je suis en overlap avec ghost donc je fait la callback associé,
	* /Pac man
	* -> food :  overlap
	* -> pomme : overlap
	* -> ghost : overlap
	* ->wall : block
	* 
	* / Ghost
	* -> food :  None
	* -> pomme : None
	* -> PacMan : overlap
	**/
	const EntityType& _type = _entity->GetType();
	if (callbacks.contains(_type))
	{
		callbacks[_type](_entity);
	}
}

void CollisionComponent::AddCallback(const EntityType& _type, const function<void(Entity* _entity)>& _callback)
{
	callbacks.insert(make_pair(_type, _callback));
}
