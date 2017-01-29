#pragma once
#include "Transform.h"
#include "AABB.h"
#include "Drawable.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Texture.h"
#include "Time.h"

class Enemy : public Drawable, public GameObject
{
public:
	Enemy(vec3 position = vec3(0, 0, 0));
	~Enemy();

	std::vector<Enemy> enemyObjects;

	void EnemyUpdate();
	void Move();
	void Die(bool incrementPoint = true);

protected:
	void setupMeshInformation();
	void draw() override;

	int moveSpeed = 1;
	int diffSpeed;

	bool dead = false;

	Mesh * mesh;
	Vertex * vertexArr;
	int numVertices;
	Texture * texture;

	float timeSinceDead;
	float respawnTime = 3;
};

