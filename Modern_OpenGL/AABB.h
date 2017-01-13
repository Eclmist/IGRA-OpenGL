#pragma once
#include <detail/type_vec3.hpp>

struct AABB
{
	AABB();
	AABB(glm::vec3 pos);
	AABB(glm::vec3 pos, glm::vec3 halfSize);
	AABB(AABB&);

	glm::vec3 pos;
	glm::vec3 halfSize; //TODO: Refactor to "Bounds" 

	glm::vec3 Size() const;
	bool CheckOverlap(const AABB &other) const;

	glm::vec3& leftBottomBack();
	glm::vec3& rightTopFront();

	float top();
	float bottom();
	float left();
	float right();
	float front();
	float back();

};
