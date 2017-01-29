#include "GameObject.h"
#include "BoxCollider.h"
#include "Rigidbody.h"
#include "Physics.h"

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
		collider->aabb.bounds = transform.getLocalScale() * vec3(0.5);

	}
	else
	{
		if (collider != nullptr)
		{
			Physics::RemoveCollider(collider);
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
