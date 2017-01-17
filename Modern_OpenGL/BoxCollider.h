#pragma once
#include "AABB.h"
#include "GameObject.h"

//class GameObject;

class BoxCollider
{
public:
	BoxCollider(GameObject &);
	~BoxCollider();

	void setAABB(glm::vec3 pos, glm::vec3 halfsize);

	int uid;
	AABB aabb;	// Why pointer to a aabb instead of storing aabb in collider
				// since aabb is only used by the collider? #changed

	GameObject & gameObject;

	static unsigned int uidCount;
};

