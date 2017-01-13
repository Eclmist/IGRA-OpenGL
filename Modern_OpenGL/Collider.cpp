#include "Collider.h"
#include "Physics.h"

unsigned int Collider::uidCount = 0;

Collider::Collider(GameObject & parent)
	: gameObject(parent)
{
	Physics::AddCollider(this);

	uid = uidCount++;
}

Collider::~Collider()
{
	Physics::RemoveCollider(this);
}

void Collider::setAABB(glm::vec3 pos, glm::vec3 halfsize) 
{
	aabb = AABB(pos, halfsize);
}
