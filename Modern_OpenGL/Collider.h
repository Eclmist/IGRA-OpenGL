#pragma once
#include "AABB.h"
#include "GameObject.h"

//class GameObject;

class Collider
{
public:
	Collider(GameObject &);
	~Collider();

	int uid;
	AABB aabb;	// Why pointer to a aabb instead of storing aabb in collider
				// since aabb is only used by the collider? #changed

	void setAABB(glm::vec3 pos, glm::vec3 halfsize);

	GameObject & gameObject;

	static unsigned int uidCount;
};

