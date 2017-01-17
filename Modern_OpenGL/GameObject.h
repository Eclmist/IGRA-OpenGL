#pragma once
#include "Transform.h"

class BoxCollider;
class Rigidbody;
class GameObject
{
public:
	GameObject(Transform);
	GameObject(GameObject &);
	GameObject(vec3 position = vec3(0));
	virtual ~GameObject();

	Transform transform;

	void SetColliderActive(bool);
	void SetRigidbodyActive(bool);

	BoxCollider * collider;
	Rigidbody * rigidbody;

};

