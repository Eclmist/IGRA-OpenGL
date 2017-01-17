#pragma once
#include "Transform.h"

class Collider;
class Rigidbody;
class GameObject
{
public:
	GameObject();
	GameObject(Transform);
	GameObject(GameObject &);
	GameObject(vec3 position);
	virtual ~GameObject();

	Transform transform;

	void SetColliderActive(bool);
	void SetRigidbodyActive(bool);

	Collider * collider;
	Rigidbody * rigidbody;

};

