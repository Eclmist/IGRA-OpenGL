#pragma once
#include "Transform.h"

class Collider;

class GameObject
{
public:
	GameObject();
	GameObject(Transform);
	GameObject(GameObject &);
	GameObject(vec3 position);
	virtual ~GameObject();

	Transform transform;

	Collider * collider;

	//will override any previouly set colliders
	virtual void setCollider();
};

