#include "Enemy.h"
#include "BoxCollider.h"
#include "GameManager.h"

Enemy::Enemy(vec3 position)
{
	texture = new Texture("resources/target.jpg");
	transform.setLocalPosition(position);
	setupMeshInformation();

	SetColliderActive(true);
	collider->aabb.halfSize = vec3(0.025, 2, 0.33);
	// TODO : make aabb pos adjustable
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
	
	if(transform.getLocalPosition().z <= -9){
		moveSpeed = 1;
	}

	if (dead) {
		transform.LerpRotation(transform.getRotation(), vec3(0, 0, 0), Time::deltaTime() * 10);

		if (timeSinceDead > respawnTime)
		{
			timeSinceDead = 0;
			dead = false;
			//SetColliderActive(true);
		}
		else
		{
			timeSinceDead += Time::deltaTime();
		}
	}
	else {
		transform.LerpRotation(transform.getRotation(), vec3(0, 0, -90), Time::deltaTime() * 10);
	}

	transform.setLocalPosition(vec3(transform.getLocalPosition().x, transform.getLocalPosition().y, transform.getLocalPosition().z + Time::deltaTime() * moveSpeed));
}

void Enemy::Die(bool incrementPoint)
{
	if (!dead)
	{
		dead = true;
		//SetColliderActive(false); TODO: Fix enemy collider reenable

		if (incrementPoint)
			GameManager::Instance->PointIncrement();
	}
}