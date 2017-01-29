/*
Written by: Ivan Leong Jit Kiong
Admin No: p1548268
*/

#pragma once
#include "Transform.h"
#include "AABB.h"
#include "Drawable.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"

class Weapon : public Drawable, public GameObject
{
public:
	Weapon(vec3 position = vec3(0, 0, 0));

	~Weapon();

	static float radius;

protected:

	void setupMeshInformation();
	void draw() override;

	Mesh * mesh;
	Vertex * vertexArr;
	int numVertices;
	Texture * texture;
};

