#include "Weapon.h"

float Weapon::radius = 1;

Weapon::Weapon(vec3 position)
{
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
	SamLoader::LoadModel("resources/model/FixedM4.obj", vertexArr, numVertices);

	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);

}

void Weapon::draw()
{
	if (texture != nullptr)
		texture->Bind();

	glEnable(GL_LIGHTING);
	glColor3f(0.1, 0.1, 0.1);
	mesh->Draw(transform);
	glDisable(GL_LIGHTING);
}
