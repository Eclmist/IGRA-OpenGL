#include "GameObject.h"
#include "Collider.h"


GameObject::GameObject()
{
	collider = new Collider(*this);
}

GameObject::GameObject(Transform t) : GameObject()
{
	transform = t;
}

GameObject::GameObject(vec3 position) : GameObject()
{
	transform.setLocalPosition(position);
}


GameObject::~GameObject()
{
	delete collider;
}

GameObject::GameObject(GameObject & other)
{
	collider = new Collider(*this);
	transform = other.transform;
	setCollider();
}

void GameObject::setCollider()
{
	if (collider == nullptr)
		collider = new Collider(*this);

	collider->aabb.pos = transform.getLocalPosition();
	collider->aabb.halfSize = transform.getLocalScale();
}
