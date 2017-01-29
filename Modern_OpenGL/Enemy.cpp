#include "Enemy.h"
#include "BoxCollider.h"
#include "GameManager.h"

Enemy::Enemy(vec3 position)
{
	texture = new Texture("resources/target.jpg");
	transform.setLocalPosition(position);
	setupMeshInformation();

	SetColliderActive(true);
	collider->aabb.bounds = vec3(0.025, 2, 0.33);
	// TODO : make aabb pos adjustable

	if (GameManager::Instance->diff == easy) {
		diffSpeed = 1;
		GameManager::Instance->targetPoints = 30;
		GameManager::Instance->totalTime = 60;
	}
	else if (GameManager::Instance->diff == medium) {
		diffSpeed = 2;
		transform.setLocalScale(vec3(0.7, 0.7, 0.7));
		GameManager::Instance->targetPoints = 25;
		GameManager::Instance->totalTime = 40;
	}
	else if (GameManager::Instance->diff == hard) {
		diffSpeed = 4;
		transform.setLocalScale(vec3(0.4, 0.4, 0.4));
		GameManager::Instance->targetPoints = 10;
		GameManager::Instance->totalTime = 20;
	}

	moveSpeed = diffSpeed;
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
		moveSpeed = -diffSpeed;
	}
	
	if(transform.getLocalPosition().z <= -9){
		moveSpeed = diffSpeed;
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