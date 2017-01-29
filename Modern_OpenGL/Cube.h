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

class Cube : public Drawable, public GameObject
{
public:
	Cube(vec3 position = vec3(0, 0, 0), bool magical = false);
	~Cube();

	static float radius;
protected:

	void setupMeshInformation();
	void draw() override;
	void SetupProceduralTex();

	Mesh * mesh;
	Vertex * vertexArr;
	int numVertices;
	Texture * texture;

	bool magical = false;

	GLubyte proceduralTex[64][64][3];
};

