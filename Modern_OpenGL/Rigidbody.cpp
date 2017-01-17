#include "Rigidbody.h"
#include "GameObject.h"
#include "Physics.h"
#include "Time.h"

Rigidbody::Rigidbody(GameObject & parent, bool g) : gameObject(parent), useGravity(g)
{
	Physics::AddRigidBody(this);
}


Rigidbody::~Rigidbody()
{
	Physics::RemoveRigidbody(this);
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

void Rigidbody::Update()
{
	vec3 currentPosition = gameObject.transform.getLocalPosition();

	if (useGravity)
	{
		velocity += Physics::Gravity;
	}

	vec3 newPosition = currentPosition += velocity * Time::deltaTime(); //Important

	gameObject.transform.setLocalPosition(newPosition);
}
