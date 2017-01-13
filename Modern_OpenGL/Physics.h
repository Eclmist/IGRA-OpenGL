#pragma once
#include "Rigidbody.h"
#include <list>
#include "RaycastHit.h"

class Physics
{

	static std::list<Collider*> colliders;
	static std::list<Rigidbody*> rigidbodies;

	static int uidCount;

public:
	Physics();
	~Physics();

	static int AddCollider(Collider* collider);
	static void RemoveCollider(Collider* collider);

	static void AddRigidBody(Rigidbody* rigidbody);
	static void RemoveRigidbody(Rigidbody* rigidbody);

	//Raycast (Does not work with non AABB colliders)
	static bool raycast(glm::vec3 origin, glm::vec3 direction, float maxDistance = INFINITY);
	static bool raycast(RaycastHit& out, vec3 v0,
		vec3 dir, float maxDistance = INFINITY);
	static bool raycast2(RaycastHit& out, vec3 v0,
		vec3 dir, float maxDistance = INFINITY);

	static void physicsAssert()
	{
		assert("Larger than it is supposed to be", colliders.size() <= glm::pow(Chunk::chunkSize, 3));
	};
};
