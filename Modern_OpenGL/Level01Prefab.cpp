#include "Level01Prefab.h"

float Level01Prefab::radius = 1;

Level01Prefab::Level01Prefab(vec3 position)
{
	texture = new Texture("resources/uv.jpg");
	transform.setLocalPosition(position);
	setupMeshInformation();
}


Level01Prefab::~Level01Prefab()
{
	delete mesh;
	//delete[] vertexArr; TODO: FIX
	delete texture;
}

#define r radius

void Level01Prefab::setupMeshInformation()
{
	SamLoader::LoadModel("resources/model/wall.obj", vertexArr, numVertices);
	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);

}

void Level01Prefab::draw()
{
	if (texture != nullptr)
		texture->Bind();

	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	mesh->Draw(transform);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
}
