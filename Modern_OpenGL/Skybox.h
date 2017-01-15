#pragma once
#include "Drawable.h"
#include "GameObject.h"
#include "Texture.h"
#include "Mesh.h"

class Skybox : public Drawable, public GameObject
{
public:
	Skybox();
	~Skybox();

	void Update(vec3 cameraPos);

protected:
	void setupMeshInformation();
	void draw() override;
	Mesh * mesh;
	Vertex * vertexArr;
	int numVertices;
	Texture * texture;
};

