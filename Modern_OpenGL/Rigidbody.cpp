#include "Rigidbody.h"
#include "GameObject.h"


Rigidbody::Rigidbody(GameObject & parent) : gameObject(parent)
{
}


Rigidbody::~Rigidbody()
{
}

bool Rigidbody::CheckCollision(Collider& other)
{
	if (gameObject.collider != nullptr) //check if collider component exist
	{
		if (other.uid == gameObject.collider->uid) return false;

		return (other.aabb.CheckOverlap(gameObject.collider->aabb));
	}

	return false;
}

void Rigidbody::Simulate()
{
}
