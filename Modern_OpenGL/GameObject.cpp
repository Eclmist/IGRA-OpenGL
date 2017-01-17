#include "GameObject.h"
#include "BoxCollider.h"
#include "Rigidbody.h"

GameObject::GameObject(vec3 position)
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
	collider = new BoxCollider(*this);
	transform = other.transform;
}

void GameObject::SetColliderActive(bool active)
{
	if (active)
	{
		if (collider == nullptr)
		{
			collider = new BoxCollider(*this);
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
