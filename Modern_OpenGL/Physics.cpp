#include "Physics.h"

std::list<BoxCollider*> Physics::colliders;
std::list<Rigidbody*> Physics::rigidbodies;

int Physics::uidCount;

vec3 Physics::Gravity = vec3(0, -9.832F, 0);

Physics::Physics()
{
}

Physics::~Physics()
{
}

int Physics::AddCollider(BoxCollider* collider)
{
	colliders.push_back(collider);
	return uidCount++;
}

void Physics::RemoveCollider(BoxCollider* collider)
{
	colliders.remove(collider);
}

void Physics::AddRigidBody(Rigidbody* rigidbody)
{
	rigidbodies.push_back(rigidbody);
}

void Physics::RemoveRigidbody(Rigidbody* rigidbody)
{
	rigidbodies.remove(rigidbody);
}

bool Physics::raycast(glm::vec3 v0, glm::vec3 dir, float maxDistance)
{
	RaycastHit hit;
	return raycast(hit, v0, dir, maxDistance);
}

//TODO: Make this work with infinity and optimize
bool Physics::raycast(RaycastHit& out, glm::vec3 v0, glm::vec3 dir, float maxDistance)
{
	RaycastHit * hit = nullptr;
	float nearestDistance = maxDistance;
	BoxCollider* nearestCollider = nullptr;

	// invd = inverse Direction (1/dir)
	float invdx = 1 / dir.x;
	float invdy = 1 / dir.y;
	float invdz = 1 / dir.z;

	//vec3 direction = glm::normalize(dir);


	// Loops through ALL colliders in physics list to check for intersection in all 3 axes
	for (BoxCollider* c : colliders)
	{
		if (glm::abs(c->aabb.pos.x - v0.x) > maxDistance ||
			glm::abs(c->aabb.pos.y - v0.y) > maxDistance ||
			glm::abs(c->aabb.pos.z - v0.z) > maxDistance)
		{
			continue;
		}

		//Check if the collider is even possibly in range (Check if max distance ray is within the bounding sphere)
		//if ((c->aabb.pos-v0).length() > maxDistance + c->aabb.bounds.length()) continue;

		//lower and upper fraction of line intersection
		float f_lower = 0;
		float f_upper = maxDistance;

		////LBB = leftBottomBack; RTF = RightTopFront;
		//vec3 LBB = c->aabb.leftBottomBack();
		//vec3 RTF = c->aabb.rightTopFront();

		float lower, upper;

		// check if ray intersects the two X bounds of the box			
		lower = (c->aabb.left() - v0.x) * invdx;
		upper = (c->aabb.right() - v0.x) * invdx;

		if (lower > upper) std::swap(lower, upper);
		if (lower > f_lower) f_lower = lower;
		if (upper < f_upper) f_upper = upper;
		if (f_lower > nearestDistance || f_upper < f_lower) continue;


		//check if ray intersects the two y bounds of the box			
		lower = (c->aabb.bottom() - v0.y) * invdy;
		upper = (c->aabb.top() - v0.y) * invdy;

		if (lower > upper) std::swap(lower, upper);
		if (lower > f_lower) f_lower = lower;
		if (upper < f_upper) f_upper = upper;
		if (f_lower > nearestDistance || f_upper < f_lower) continue;


		//// check if ray intersects the two z bounds of the box			
		lower = (c->aabb.back() - v0.z) * invdz;
		upper = (c->aabb.front() - v0.z) * invdz;

		if (lower > upper) std::swap(lower, upper);
		if (lower > f_lower) f_lower = lower;
		if (upper < f_upper) f_upper = upper;
		if (f_lower > nearestDistance || f_upper < f_lower) continue;

		if (f_lower < nearestDistance)
		{
			nearestDistance = f_lower;
			nearestCollider = c;
		}
	}

	if (nearestCollider != nullptr)
	{
		delete hit;
		hit = new RaycastHit(*nearestCollider, v0 + nearestDistance * glm::normalize(dir), v0);
		out = RaycastHit(*hit);

		return true;
	}

	return false;
}

//bool Physics::raycast2(RaycastHit& out, glm::vec3 v0, glm::vec3 dir, float maxDistance)
//{
//	RaycastHit * hit = nullptr;
//	double nearestDistance = INFINITY;
//
//	// v0 = origin
//	// v1 = target
//	glm::vec3 v1 = v0 + dir * maxDistance;
//
//	//vec3 direction = glm::normalize(dir);
//
//	// Loops through ALL colliders in physics list to check for intersection in all 3 axes
//	for (BoxCollider* c : colliders)
//	{
//		//lower and upper fraction of line intersection
//		float f_lower = 0;
//		float f_upper = 1;
//
//		// check if ray intersects the two X bounds of the box
//		float lower, upper;
//
//		lower = (c->aabb.left() - v0.x) / (v1.x - v0.x);
//		upper = (c->aabb.right() - v0.x) / (v1.x - v0.x);
//
//		if (lower > upper) std::swap(lower, upper);
//		if (lower < 0) lower = 0;
//		if (upper > 1) upper = 1;
//		if (lower > f_lower) f_lower = lower;
//		if (upper < f_upper) f_upper = upper;
//
//		//check if ray intersects the two y bounds of the box
//
//		lower = (c->aabb.bottom() - v0.y) / (v1.y - v0.y);
//		upper = (c->aabb.top() - v0.y) / (v1.y - v0.y);
//
//		if (lower > upper) std::swap(lower, upper);
//		if (lower < 0) lower = 0;
//		if (upper > 1) upper = 1;
//
//		if (lower > f_lower) f_lower = lower;
//		if (upper < f_upper) f_upper = upper;
//
//		//// check if ray intersects the two z bounds of the boz
//
//		lower = (c->aabb.back() - v0.z) / (v1.z - v0.z);
//		upper = (c->aabb.front() - v0.z) / (v1.z - v0.z);
//
//		if (lower > upper) std::swap(lower, upper);
//		if (lower < 0) lower = 0;
//		if (upper > 1) upper = 1;
//
//		if (lower > f_lower) f_lower = lower;
//		if (upper < f_upper) f_upper = upper;
//
//		if (f_upper > f_lower)
//		{
//			if (f_lower < nearestDistance)
//			{
//				nearestDistance = f_lower;
//				delete hit;
//				hit = new RaycastHit(*c, v0 + f_lower * glm::normalize(dir), v0);
//			}
//		}
//	}
//
//	if (hit != nullptr)
//	{
//		out = RaycastHit(*hit);
//
//		return true;
//	}
//
//	return false;
//}

bool Physics::CheckAABBCollision(AABB & aabb)
{
	for each (BoxCollider * c in colliders)
	{
		if (c->aabb.uid != aabb.uid) {
			if (CheckAABBCollision(aabb, c->aabb))
				return true;
		}
	}

	return false;
}

bool Physics::CheckAABBCollision(AABB & a, AABB & b)
{
	return CheckAABBCollision(a.pos, a.bounds, b.pos, b.bounds);
}

bool Physics::CheckAABBCollision(AABB & a, vec3 oPos, vec3 oHalfsize)
{
	return CheckAABBCollision(a.pos, a.bounds, oPos, oHalfsize);
}

bool Physics::CheckAABBCollision(vec3 pos, vec3 halfsize, vec3 oPos, vec3 oHalfsize)
{
	if ((oPos - pos).length() > oHalfsize.length() + halfsize.length()) return false;

	vec3 oUpperBounds = oPos + oHalfsize;
	vec3 oLowerBounds = oPos - oHalfsize;

	vec3 upperBounds = pos + halfsize;
	vec3 lowerBounds = pos - halfsize;

	return (upperBounds.x > oLowerBounds.x && lowerBounds.x < oUpperBounds.x) &&
		(upperBounds.y > oLowerBounds.y && lowerBounds.y < oUpperBounds.y) &&
		(upperBounds.z > oLowerBounds.z && lowerBounds.z < oUpperBounds.z);
}

void Physics::PhysicsUpdate()
{

	for each (BoxCollider * bc in colliders)
	{	

		bc->aabb.UpdatePosition();
	}

	for each (Rigidbody* rb in rigidbodies)
	{
		rb->Update();
	}
}

void Physics::Reset()
{

	for (auto &it : colliders) {
		delete it;
	} 
	
	colliders.clear();

	for (auto &it : rigidbodies) delete it; rigidbodies.clear();
}

