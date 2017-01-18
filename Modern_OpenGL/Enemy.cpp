#include "Enemy.h"



Enemy::Enemy(vec3 position)
{
	texture = new Texture("resources/target.jpg");
	transform.setLocalPosition(position);
	setupMeshInformation();

	SetColliderActive(true);
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

void Enemy::EnemyUpdate() {

	if (transform.getLocalPosition().z >= 5) {
		moveSpeed = -1;
	}
	else if(transform.getLocalPosition().z <= -5){
		moveSpeed = 1;
	}

	if (dead) {
		transform.LerpRotation(transform.getRotation(), vec3(0, 0, 0), Time::deltaTime() * 10);
		SetColliderActive(false);
	}
	else {
		transform.setLocalPosition(vec3(transform.getLocalPosition().x, transform.getLocalPosition().y, transform.getLocalPosition().z + 0.01f * moveSpeed));
		transform.LerpRotation(transform.getRotation(), vec3(0, 0, -90), Time::deltaTime() * 10);
	}
}

void Enemy::Die() 
{
	dead = true;
}