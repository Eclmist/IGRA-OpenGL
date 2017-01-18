#include "Weapon.h"

float Weapon::radius = 1;

Weapon::Weapon(vec3 position)
{
	texture = new Texture("resources/Awp.bmp");
	transform.setLocalPosition(position);
	setupMeshInformation();
}


Weapon::~Weapon()
{
	delete mesh;
	//delete[] vertexArr; TODO: FIX
	delete texture;
}

#define r radius

void Weapon::setupMeshInformation()
{
	SamLoader::LoadModel("resources/model/awp.obj", vertexArr, numVertices);

	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);

}

void Weapon::draw()
{
	if (texture != nullptr)
		texture->Bind();

	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	mesh->Draw(transform);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
}
