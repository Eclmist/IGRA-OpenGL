#include "Cube.h"

float Cube::radius = 1;

Cube::Cube(vec3 position)
{
	texture = new Texture("resources/Cube1.jpg");
	transform.setLocalPosition(position);
	setupMeshInformation();
}


Cube::~Cube()
{
	delete mesh;
	//delete[] vertexArr; TODO: FIX
	delete texture;
}

#define r radius

void Cube::setupMeshInformation()
{
	SamLoader::LoadModel("resources/model/cube.obj", vertexArr, numVertices);
	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);

}

void Cube::draw()
{
	if (texture != nullptr)
		texture->Bind();

	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	mesh->Draw(transform);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
