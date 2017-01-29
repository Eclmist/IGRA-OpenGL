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
	texture = new Texture("resources/Cube1.jpg");

	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);

}

void Weapon::draw()
{
	glEnable(GL_TEXTURE);
	glEnable(GL_LIGHTING);
	GLfloat grey[] = { 0.3, 0.3, 0.3, 0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, grey);
	mesh->Draw(transform, false);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE);
}

