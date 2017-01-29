#include "table.h"

float table::radius = 1;

table::table(vec3 position)
{
	texture = new Texture("resources/table.png");
	transform.setLocalPosition(position);
	setupMeshInformation();
}


table::~table()
{
	delete mesh;
	//delete[] vertexArr; TODO: FIX
	delete texture;
}

#define r radius

void table::setupMeshInformation()
{
	SamLoader::LoadModel("resources/model/table.obj", vertexArr, numVertices);
	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);

}

void table::draw()
{
	if (texture != nullptr)
		texture->Bind();

	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	mesh->Draw(transform);

	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
