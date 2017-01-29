#include "AABB.h"
#include <glm.hpp>
#include "GameObject.h"

unsigned int AABB::uidCurrent = 0;

AABB::AABB(GameObject & gameObject, glm::vec3 pos, glm::vec3 halfSize) : pos(pos), bounds(halfSize), gameObject(gameObject)
{
	uid = uidCurrent++;
}

AABB::AABB(AABB & other) : gameObject(*new GameObject())
{
	pos = other.pos;
	bounds = other.bounds;
	uid = other.uid;
}

glm::vec3 AABB::Size() const
{
	return bounds * 2.0f;
}

// Deprecated: use Physics::Check
bool AABB::CheckOverlap(const AABB& other) const
{
	//Optimization - Check if close enough for any collision to occur
	if ((other.pos - pos).length() > other.bounds.length() + bounds.length()) return false;

	if (glm::abs(pos.x - other.pos.x) < bounds.x + other.bounds.x &&
		glm::abs(pos.y - other.pos.y) < bounds.y + other.bounds.y &&
		glm::abs(pos.z - other.pos.z) < bounds.z + other.bounds.z)
		return true;
	return false;
}

void AABB::UpdatePosition()
{
	pos = gameObject.transform.getLocalPosition();
}

glm::vec3& AABB::leftBottomBack()
{
	return pos - bounds;
}

glm::vec3& AABB::rightTopFront()
{
	return pos + bounds;
}

float AABB::top()
{
	return pos.y + bounds.y;
}

float AABB::bottom()
{
	return pos.y - bounds.y;
}

float AABB::left()
{
	return pos.x - bounds.x;
}

float AABB::right()
{
	return pos.x + bounds.x;
}

float AABB::front()
{
	return pos.z + bounds.z;
}

float AABB::back()
{
	return pos.z - bounds.z;
}
