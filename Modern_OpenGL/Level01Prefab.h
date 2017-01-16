#pragma once
#include "Transform.h"
#include "AABB.h"
#include "Drawable.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"

class Level01Prefab : public Drawable, public GameObject
{
public:
	Level01Prefab(vec3 position = vec3(0, 0, 0));
	~Level01Prefab();

	static float radius;
protected:

	void setupMeshInformation();
	void draw() override;

	Mesh * mesh;
	Vertex * vertexArr;
	int numVertices;
	Texture * texture;
};

