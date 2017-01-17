#include "GameObject.h"
#include "Collider.h"
#include "Rigidbody.h"

GameObject::GameObject()
{
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
	SetColliderActive(false);
	SetRigidbodyActive(false);
}

GameObject::GameObject(GameObject & other)
{
	collider = new Collider(*this);
	transform = other.transform;
}

void GameObject::SetColliderActive(bool active)
{
	if (active)
	{
		if (collider == nullptr)
		{
			collider = new Collider(*this);
		}
		collider->aabb.pos = transform.getLocalPosition();
		collider->aabb.halfSize = transform.getLocalScale();

	}
	else
	{
		if (collider != nullptr)
		{
			delete collider;
			collider = nullptr;
		}
	}
}

void GameObject::SetRigidbodyActive(bool active)
{
	if (active)
	{
		if (rigidbody == nullptr)
		{
			rigidbody = new Rigidbody(*this);
		}
	}
	else
	{
		if (rigidbody != nullptr)
		{
			delete rigidbody;
			rigidbody = nullptr;
		}
	}
}
