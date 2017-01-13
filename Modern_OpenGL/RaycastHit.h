#pragma once
#include "Collider.h"
#include "Rigidbody.h"
#include "Transform.h"

class RaycastHit
{
public:
	//Only create pointers of this class! do not new or instantiate objects of this class.
	RaycastHit();
	//Origin is the start point of ray
	RaycastHit(Collider &, vec3 hitPoint, vec3 origin);
	RaycastHit(RaycastHit &);

	~RaycastHit();

	Collider * collider;
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
	void CalculateHitSide(Collider & colliderHit, vec3 hitPoint);
};

