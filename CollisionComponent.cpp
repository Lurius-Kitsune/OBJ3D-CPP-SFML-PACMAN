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

	callbacks[_entity->GetType()](_entity);

	/*for (const auto& _callback : callbacks)
	{
		if (_callback.first == _entity->)
	}

	if (type == CT_OVERLAP)
	{
		return callback(_entity);
	}
	return type != CT_BLOCK;*/
}

void CollisionComponent::AddCallback(const EntityType& _type, const function<void(Entity* _entity)>& _callback)
{
	callbacks.insert(make_pair(_type, _callback));
}
