#pragma once
#include "Collider.h"

class Rigidbody
{
	glm::vec3 velocity;

public:
	Rigidbody(GameObject &);
	~Rigidbody();

	bool CheckCollision(Collider& other);
	void Simulate();

	GameObject & gameObject;
};

