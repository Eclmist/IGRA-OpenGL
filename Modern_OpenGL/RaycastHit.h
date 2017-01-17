#pragma once
#include "BoxCollider.h"
#include "Rigidbody.h"
#include "Transform.h"

class RaycastHit
{
public:
	//Only create pointers of this class! do not new or instantiate objects of this class.
	RaycastHit();
	//Origin is the start point of ray
	RaycastHit(BoxCollider &, vec3 hitPoint, vec3 origin);
	RaycastHit(RaycastHit &);

	~RaycastHit();

	BoxCollider * collider;
	vec3 point;
	vec3 origin;
	float distance;
	Transform * transform;

	enum Sides{
		LEFT,
		RIGHT,
		FRONT,
		BACK,
		TOP,
		BOTTOM,
	};

	Sides hitSide;

private:
	void CalculateHitSide(BoxCollider & colliderHit, vec3 hitPoint);
};

