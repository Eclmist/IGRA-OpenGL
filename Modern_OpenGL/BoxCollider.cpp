#include "BoxCollider.h"
#include "Physics.h"

unsigned int BoxCollider::uidCount = 0;

BoxCollider::BoxCollider(GameObject & parent)
	: gameObject(parent), aabb(parent)
{
	Physics::AddCollider(this);

	uid = uidCount++;
}

BoxCollider::~BoxCollider()
{
	Physics::RemoveCollider(this);
}

void BoxCollider::setAABB(glm::vec3 pos, glm::vec3 halfsize)
{
	aabb.pos = pos;
	aabb.halfSize = halfsize;
}