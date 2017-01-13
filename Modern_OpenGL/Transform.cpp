#include "Transform.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

Transform::Transform(vec3 position, vec3 rotation, vec3 localScale) :
	position(position), rotation(rotation), localScale(localScale)
{
}

Transform::~Transform()
{
}

void Transform::setLocalPosition(vec3 newPos)
{
	position = newPos;
}

vec3 Transform::getLocalPosition() const
{
	return position;
}

mat4 Transform::getLocalPositionMatrix() const
{
	return translate(mat4(), position);
}

void Transform::setRotation(vec3 newRot)
{
	rotation = newRot;
}

vec3 Transform::getRotation() const
{
	return rotation;
}

mat4 Transform::getRotationMatrix() const
{
	mat4 out = mat4();

	out = rotate(out, rotation.x, vec3(1, 0, 0));
	out = rotate(out, rotation.y, vec3(0, 1, 0));
	out = rotate(out, rotation.z, vec3(0, 0, 1));

	return out;
}

void Transform::setLocalScale(vec3 newScale)
{
	localScale = newScale;
}

vec3 Transform::getLocalScale() const
{
	return localScale;
}

mat4 Transform::getLocalScaleMatrix() const
{
	return scale(mat4(), localScale);
}

mat4 Transform::getModelMatrix()
{
	return getLocalPositionMatrix() * getRotationMatrix()  * getLocalScaleMatrix();
}
