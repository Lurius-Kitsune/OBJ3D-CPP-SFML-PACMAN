#include "GhostMovementCompenent.h"

GhostMovementCompenent::GhostMovementCompenent(Entity* _owner) : MovementComponent(_owner)
{

}

void GhostMovementCompenent::Update()
{
	Super::Update();


}

void GhostMovementCompenent::ComputeNewDirection()
{
	const vector<Vector2i>& _allDirection =
	{
		Vector2i(0, -1),
		Vector2i(0, 1),
		Vector2i(-1, 0),
		Vector2i(1, 0)
	};
	Vector2i _newDirection;
	do
	{
		_newDirection = _allDirection[RandomInt(0, 3)];
	} while (_newDirection != direction);
}
