#pragma once
#include <glm.hpp>

class GameObject;
using namespace glm;

class Transform
{
public:
	Transform(vec3 localPosition = vec3(0, 0, 0),
		vec3 rotation = vec3(0, 0, 0),
		vec3 localScale = vec3(1, 1, 1));
	~Transform();

	void setParent(Transform &);

	vec3 getPosition();

	void setLocalPosition(vec3 newPos);
	vec3 getLocalPosition() const;
	mat4 getLocalPositionMatrix() const;

	void setRotation(vec3 newRot);
	void LerpRotation(vec3 source, vec3 destination, float factor);
	vec3 getRotation() const;
	mat4 getRotationMatrix() const;

	void setLocalScale(vec3 newScale);
	vec3 getLocalScale() const;
	mat4 getLocalScaleMatrix() const;

	mat4 getModelMatrix();

	Transform * parent;

private:
	vec3 position;
	vec3 rotation;
	vec3 localScale;
};

