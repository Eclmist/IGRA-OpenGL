#pragma once
#include "Transform.h"
#include "AABB.h"
#include "Drawable.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"

class Enemy : public Drawable, public GameObject
{
public:
	Enemy(vec3 position = vec3(0, 0, 0));
	~Enemy();

	void Die();

protected:
	void setupMeshInformation();
	void draw() override;

	Mesh * mesh;
	Vertex * vertexArr;
	int numVertices;
	Texture * texture;
};
