#pragma once
#include "Transform.h"
#include "AABB.h"
#include "Drawable.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"

class Awp : public Drawable, public GameObject
{
public:
	Awp(vec3 position = vec3(0, 0, 0));

	~Awp();

	static float radius;
protected:

	void setupMeshInformation();
	void draw() override;

	Mesh * mesh;
	Vertex * vertexArr;
	int numVertices;
	Texture * texture;
};

