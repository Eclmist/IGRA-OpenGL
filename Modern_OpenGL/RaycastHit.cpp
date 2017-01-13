#include "RaycastHit.h"
#include "GameObject.h"

RaycastHit::RaycastHit()
{
}

RaycastHit::RaycastHit(Collider & colliderHit, vec3 hitPoint,
	vec3 origin) : 
	collider(&colliderHit), point (hitPoint), origin(origin)
{
	distance = glm::distance(point, origin);
	transform = &collider->gameObject.transform;
	//TODO: Implement hit normals calculation;


	CalculateHitSide(colliderHit, hitPoint);
}

RaycastHit::RaycastHit(RaycastHit& other)
{
	collider = other.collider;
	point = other.point;
	origin = other.origin;
	transform = other.transform;
	distance = other.distance;
	hitSide = other.hitSide;
}

RaycastHit::~RaycastHit()
{
}

#define LENIENCY 0.001F

void RaycastHit::CalculateHitSide(Collider & colliderHit, vec3 hitPoint)
{
	vec3 target = colliderHit.aabb.pos;
	vec3 halfsize = colliderHit.aabb.halfSize;
	if (glm::abs(hitPoint.x - (target.x - halfsize.x)) < LENIENCY)
	{
		hitSide = LEFT;
	}
	else if (glm::abs(hitPoint.x - (target.x + halfsize.x)) < LENIENCY)
	{
		hitSide = RIGHT;
	}
	else if (glm::abs(hitPoint.y - (target.y - halfsize.y)) < LENIENCY)
	{
		hitSide = BOTTOM;
	}
	else if (glm::abs(hitPoint.y - (target.y + halfsize.y)) < LENIENCY)
	{
		hitSide = TOP;
	}
	else if (glm::abs(hitPoint.z- (target.z - halfsize.z)) < LENIENCY)
	{
		hitSide = BACK;
	}
	else
	{
		hitSide = FRONT;
	}
}