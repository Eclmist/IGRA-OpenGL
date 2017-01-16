#include "Awp.h"

float Awp::radius = 1;

Awp::Awp(vec3 position)
{
	texture = new Texture("resources/Awp.bmp");
	transform.setLocalPosition(position);
	setupMeshInformation();
}


Awp::~Awp()
{
	delete mesh;
	//delete[] vertexArr; TODO: FIX
	delete texture;
}

#define r radius

void Awp::setupMeshInformation()
{
	SamLoader::LoadModel("resources/model/awp.obj", vertexArr, numVertices);

	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);

}

void Awp::draw()
{
	if (texture != nullptr)
		texture->Bind();

	glEnable(GL_TEXTURE_2D);
	mesh->Draw(transform);
	glDisable(GL_TEXTURE_2D);
}
