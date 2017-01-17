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


//TODO : FIX OVERLAP BUG
void Rigidbody::Update()
{
	vec3 currentPosition = gameObject.transform.getLocalPosition();

	if (useGravity)
	{
		velocity += Physics::Gravity * Time::deltaTime();
	}

	vec3 newPosition = currentPosition + velocity * Time::deltaTime();

	if (gameObject.collider != nullptr)
	{
		AABB temp = AABB(gameObject.collider->aabb) ;
		temp.pos = newPosition;

		if (Physics::CheckAABBCollision(temp))
		{
			velocity = vec3(0);
			newPosition = currentPosition + velocity * Time::deltaTime();

			RaycastHit hit;
			//Physics::raycast(currentPosition)
		}
	}

	gameObject.transform.setLocalPosition(newPosition);
}
