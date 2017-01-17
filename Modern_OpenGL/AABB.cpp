#include "AABB.h"
#include <glm.hpp>
#include "GameObject.h"

unsigned int AABB::uidCurrent = 0;

AABB::AABB(GameObject & gameObject, glm::vec3 pos, glm::vec3 halfSize) : pos(pos), halfSize(halfSize), gameObject(gameObject)
{
	uid = uidCurrent++;
}

AABB::AABB(AABB & other) : gameObject(*new GameObject())
{
	pos = other.pos;
	halfSize = other.halfSize;
	uid = other.uid;
}

glm::vec3 AABB::Size() const
{
	return halfSize * 2.0f;
}

// Deprecated: use Physics::Check
bool AABB::CheckOverlap(const AABB& other) const
{
	//Optimization - Check if close enough for any collision to occur
	if ((other.pos - pos).length() > other.halfSize.length() + halfSize.length()) return false;

	if (glm::abs(pos.x - other.pos.x) < halfSize.x + other.halfSize.x &&
		glm::abs(pos.y - other.pos.y) < halfSize.y + other.halfSize.y &&
		glm::abs(pos.z - other.pos.z) < halfSize.z + other.halfSize.z)
		return true;
	return false;
}

void AABB::UpdatePosition()
{
	pos = gameObject.transform.getLocalPosition();
}

glm::vec3& AABB::leftBottomBack()
{
	return pos - halfSize;
}

glm::vec3& AABB::rightTopFront()
{
	return pos + halfSize;
}

float AABB::top()
{
	return pos.y + halfSize.y;
}

float AABB::bottom()
{
	return pos.y - halfSize.y;
}

float AABB::left()
{
	return pos.x - halfSize.x;
}

float AABB::right()
{
	return pos.x + halfSize.x;
}

float AABB::front()
{
	return pos.z + halfSize.z;
}

float AABB::back()
{
	return pos.z - halfSize.z;
}
