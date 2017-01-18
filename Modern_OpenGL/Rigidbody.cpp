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


#define RESOLUTION_ITERATION 10

//TODO : FIX OVERLAP BUG
void Rigidbody::Update()
{
	vec3 currentPosition = gameObject.transform.getLocalPosition();

	if (useGravity)
	{
		velocity += Physics::Gravity * Time::deltaTime();
	}

	velocity += perFrameForce;
	perFrameForce = vec3(0);

	// == Clamping final velocity == // TODO: REPLACE

	vec3 horizontalVel = velocity;
	horizontalVel.y = 0;

	vec3 verticalVel = velocity;
	horizontalVel.x = 0;
	horizontalVel.z = 0;

	if (horizontalVel.length() > maxHorizontalVel) horizontalVel = horizontalVel / vec3(horizontalVel.length()) * maxHorizontalVel;
	if (verticalVel.length() > maxVerticalVel) verticalVel = verticalVel / vec3(verticalVel.length()) * maxVerticalVel;

	velocity = horizontalVel + verticalVel;
	
	// VELOCITY FINALIZED FOR THIS FRAME

	vec3 newPosition = currentPosition + velocity * Time::deltaTime();

	if (gameObject.collider != nullptr)
	{
		AABB temp = AABB(gameObject.collider->aabb) ;
		temp.pos = newPosition;
		if (Physics::CheckAABBCollision(temp))
		{
			velocity = vec3(0);
			
			bool hit = true;
			vec3 checkPoint = temp.pos;
			vec3 startPoint = currentPosition;
			vec3 halfVel = (checkPoint - startPoint) * vec3(0.5);

			// Collision resolution
			for (int i = 0; i < RESOLUTION_ITERATION; i++)
			{
				if (hit)
				{
					checkPoint -= halfVel;
				}
				else
				{
					checkPoint += halfVel;
				}

				temp.pos = checkPoint;
				hit = Physics::CheckAABBCollision(temp);
				halfVel *= vec3(0.5f);
			}

			newPosition = checkPoint;
		}
	}

	gameObject.transform.setLocalPosition(newPosition);
}

void Rigidbody::AddForce(vec3 force)
{
	perFrameForce += force;
}

void Rigidbody::ClampHorizontalVelocity(float max)
{
	maxHorizontalVel = max;
}

void Rigidbody::ClampVerticalVelocity(float max)
{
	maxVerticalVel = max;
}
