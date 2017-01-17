#pragma once
#include "Rigidbody.h"
#include <list>
#include "RaycastHit.h"

class Physics
{

	static std::list<BoxCollider*> colliders;
	static std::list<Rigidbody*> rigidbodies;

	static int uidCount;

public:
	Physics();
	~Physics();

	static int AddCollider(BoxCollider* collider);
	static void RemoveCollider(BoxCollider* collider);

	static void AddRigidBody(Rigidbody* rigidbody);
	static void RemoveRigidbody(Rigidbody* rigidbody);

	//Raycast (Does not work with non AABB colliders)
	static bool raycast(glm::vec3 origin, glm::vec3 direction, float maxDistance = INFINITY);
	static bool raycast(RaycastHit& out, vec3 v0, vec3 dir, float maxDistance = INFINITY);
	//static bool raycast2(RaycastHit& out, vec3 v0,
	//	vec3 dir, float maxDistance = INFINITY);

	static bool CheckAABBCollision(AABB & aabb);
	static bool CheckAABBCollision(AABB &, AABB &);
	static bool CheckAABBCollision(AABB &, vec3 oPos, vec3 oHalfsize);
	static bool CheckAABBCollision(vec3 pos, vec3 halfsize, vec3 oPos, vec3 oHalfsize);

	static void PhysicsUpdate();
	static void Reset();


	static void physicsAssert()
	{
		assert("Larger than it is supposed to be", colliders.size() <= glm::pow(Chunk::chunkSize, 3));
	};

	static vec3 Gravity;

};
