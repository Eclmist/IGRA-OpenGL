#pragma once
#include <detail/type_vec3.hpp>

class GameObject;

struct AABB
{
	AABB(GameObject &, glm::vec3 pos = glm::vec3(0.0f), glm::vec3 halfSize = glm::vec3(0.0f));
	AABB(AABB& other);

	unsigned int uid;

	glm::vec3 pos;
	glm::vec3 bounds;

	glm::vec3 Size() const;
	bool CheckOverlap(const AABB &other) const;

	void UpdatePosition();

	glm::vec3& leftBottomBack();
	glm::vec3& rightTopFront();

	float top();
	float bottom();
	float left();
	float right();
	float front();
	float back();

	GameObject & gameObject;

private:
	static unsigned int uidCurrent;

};
