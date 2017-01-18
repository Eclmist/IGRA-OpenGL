#include "Level01.h"
#include "Skybox.h"
#include "EngineCore.h"
#include "Cube.h"
#include "Level01Prefab.h"

Level01::Level01()
{
	name = "Level01";
}

Level01::~Level01()
{
	delete skybox;
	delete player;
}

void Level01::Load()
{
	skybox = new Skybox();
	player = new Player(vec3(5, 100, 5));

	graphicsHandler = new GraphicsHandler();

	gameobjects.push_back(new Cube(vec3(0, 100, 0)));
	gameobjects[0]->SetColliderActive(true);
	gameobjects[0]->SetRigidbodyActive(true);
	gameobjects.push_back(new Cube(vec3(0, -0.51, 0)));
	gameobjects[1]->transform.setLocalScale(vec3(50, 1, 50));
	gameobjects[1]->SetColliderActive(true);

	gameobjects.push_back(new Cube(vec3(0.5f, 93, 0)));
	gameobjects[2]->SetColliderActive(true);
	gameobjects[2]->SetRigidbodyActive(true);
	gameobjects.push_back(new Cube(vec3(0, 104, 0.5f)));
	gameobjects[3]->SetColliderActive(true);
	gameobjects[3]->SetRigidbodyActive(true);
	gameobjects.push_back(new Cube(vec3(0.5f, 109, 0.5f)));
	gameobjects[4]->SetColliderActive(true);
	gameobjects[4]->SetRigidbodyActive(true);
	gameobjects.push_back(new Cube(vec3(-0.5f, 107, 0)));
	gameobjects[5]->SetColliderActive(true);
	gameobjects[5]->SetRigidbodyActive(true);

	gameobjects.push_back(new Level01Prefab(vec3(0, 0, 0)));

	gameobjects.push_back(new Weapon(vec3(0, 0, 0)));
	gameobjects[7]->transform.setLocalScale(vec3(0.2775));

	loaded = true;
}

void Level01::Update()
{
	
	skybox->Update(player->transform.getLocalPosition());
	player->Update();

	//vec3 awpTargetPos = camera.pos - camera.right * wp_right +
	//	camera.dir * wp_forward - (camera.up * wp_up);

	//vec3 lerpVector = awpTargetPos - gameobjects[0]->transform.getLocalPosition();

	//gameobjects[0]->transform.setLocalPosition(gameobjects[0]->transform.getLocalPosition() + lerpVector *
	//	vec3(Time::deltaTime() * 50));
	//gameobjects[0]->transform.setRotation(vec3(-camera.pitch, -camera.yaw + 90, 0));


	if (Input::getKey('P'))
		sceneDebug = true;


	if (sceneDebug)
	{
		if (Input::getKey('I')) player->wp_up -= vec3(0.002F);
		if (Input::getKey('L')) player->wp_right += vec3(0.002F);
		if (Input::getKey('J')) player->wp_right -= vec3(0.002F);
		if (Input::getKey('K')) player->wp_up += vec3(0.002F);
		if (Input::getKey('U')) player->wp_forward += vec3(0.002F);
		if (Input::getKey('O')) player->wp_forward -= vec3(0.002F);

		if (Input::getKey('T')) debugStringYPos += 0.01F;
		if (Input::getKey('F')) debugStringXPos -= 0.01F;
		if (Input::getKey('G')) debugStringYPos -= 0.01F;
		if (Input::getKey('H')) debugStringXPos += 0.01F;


		if (Input::getKey('M')) gameobjects[0]->transform.setLocalPosition(vec3(0,100,0));

		if (Input::getKey('V')) player->camera.fov -= 0.01F;
		if (Input::getKey('B')) player->camera.fov += 0.01F;

		debugLine1 = "x: " + std::to_string(player->transform.getLocalPosition().x)
			+ " y: " + std::to_string(player->transform.getLocalPosition().y)
			+ " z: " + std::to_string(player->transform.getLocalPosition().z);

		debugLine2 = "wp_up: " + std::to_string(player->wp_up.x)
			+ " wp_right: " + std::to_string(player->wp_right.x)
			+ " wp_forward: " + std::to_string(player->wp_forward.x);

		debugLine3 = "deltaTime: " + std::to_string(Time::deltaTime())
			+ " (" + std::to_string(1 / Time::deltaTime())
			+ "fps)";


		debugLine4 = "cube1 vel x: " + std::to_string(gameobjects[0]->rigidbody->velocity.x)
			+ " y: " + std::to_string(gameobjects[0]->rigidbody->velocity.y)
			+ " z: " + std::to_string(gameobjects[0]->rigidbody->velocity.z);

		debugLine5 = "cube1 pos x: " + std::to_string(gameobjects[0]->transform.getLocalPosition().x)
			+ " y: " + std::to_string(gameobjects[0]->transform.getLocalPosition().y)
			+ " z: " + std::to_string(gameobjects[0]->transform.getLocalPosition().z);

		debugLine6 = "fov: " + std::to_string(player->camera.fov);

	}

	Draw();
}

void Level01::Draw()
{
	Scene::Draw();
	graphicsHandler->drawCollage();
}
