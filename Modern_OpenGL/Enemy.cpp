#include "Enemy.h"



Enemy::Enemy(vec3 position)
{
	texture = new Texture("resources/target.jpg");
	transform.setLocalPosition(position);
	setupMeshInformation();
}


Enemy::~Enemy()
{
	delete mesh;
	delete texture;
}

void Enemy::setupMeshInformation() 
{
	SamLoader::LoadModel("resources/model/target.obj", vertexArr, numVertices);
	mesh = new Mesh(vertexArr, numVertices, TRIANGLES);
}

void Enemy::draw()
{
	if (texture != nullptr)
		texture->Bind();
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	mesh->Draw(transform);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
}

void Enemy::Die() 
{
	transform.setRotation(vec3(-90, 0, 0));
}