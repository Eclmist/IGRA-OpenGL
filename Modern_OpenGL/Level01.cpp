#include "Level01.h"
#include "Skybox.h"
#include "EngineCore.h"
#include "Awp.h"
#include "Cube.h"
#include "Level01Prefab.h"

Level01::Level01()
{
	name = "Level01";
	skybox = new Skybox();
}

Level01::~Level01()
{
}

void Level01::Load()
{
	graphicsHandler = new GraphicsHandler();
	gameobjects.push_back(new Awp(vec3(0, 0, 0)));
	camera.pos = vec3(-30, 10, -30);
	camera.dir = vec3(-1, 0, -1);

	gameobjects.push_back(new Cube(vec3(0, 100, 0)));
	gameobjects[1]->SetColliderActive(true);
	gameobjects[1]->SetRigidbodyActive(true);

	gameobjects.push_back(new Cube(vec3(0, -0.5, 0)));
	gameobjects[2]->transform.setLocalScale(vec3(50, 1, 50));
	gameobjects[2]->SetColliderActive(true);

	//gameobjects.push_back(new Cube(vec3(1, 43, 0)));
	//gameobjects[3]->SetColliderActive(true);
	//gameobjects[3]->SetRigidbodyActive(true);
	//gameobjects.push_back(new Cube(vec3(0, 54, 1)));
	//gameobjects[4]->SetColliderActive(true);
	//gameobjects[4]->SetRigidbodyActive(true);
	//gameobjects.push_back(new Cube(vec3(1, 59, 1)));
	//gameobjects[5]->SetColliderActive(true);
	//gameobjects[5]->SetRigidbodyActive(true);
	//gameobjects.push_back(new Cube(vec3(-1, 57, 0)));
	//gameobjects[6]->SetColliderActive(true);
	//gameobjects[6]->SetRigidbodyActive(true);


	gameobjects.push_back(new Level01Prefab(vec3(0, 0, 0)));
	loaded = true;

}

float f = 0;
vec3 wp_right = vec3(0.56F);
vec3 wp_forward = vec3(0.68F);
vec3 wp_up = vec3(0.66F);

void Level01::Update()
{
	camera.UpdateCamera();
	skybox->Update(camera.pos);


	vec3 awpTargetPos = camera.pos - camera.right * wp_right +
		camera.dir * wp_forward - (camera.up * wp_up);

	vec3 lerpVector = awpTargetPos - gameobjects[0]->transform.getLocalPosition();

	gameobjects[0]->transform.setLocalPosition(gameobjects[0]->transform.getLocalPosition() + lerpVector *
		vec3(Time::deltaTime() * 30));
	gameobjects[0]->transform.setRotation(vec3(-camera.pitch, -camera.yaw + 90, 0));


	if (Input::getKeyDown('Z'))
	{
		vec3 currentPosVec = gameobjects[0]->transform.getLocalPosition();

		currentPosVec -= camera.dir * vec3(0.1F);
		
		gameobjects[0]->transform.setLocalPosition(currentPosVec);
	}

	if (Input::getKeyDown('P'))
		sceneDebug = !sceneDebug;


	if (sceneDebug)
	{
		if (Input::getKeyDown('I')) wp_up -= vec3(0.01F);
		if (Input::getKeyDown('L')) wp_right += vec3(0.01F);
		if (Input::getKeyDown('J')) wp_right -= vec3(0.01F);
		if (Input::getKeyDown('K')) wp_up += vec3(0.01F);

		if (Input::getKeyDown('U')) wp_forward += vec3(0.01F);
		if (Input::getKeyDown('O')) wp_forward -= vec3(0.01F);

		if (Input::getKeyDown('M')) gameobjects[1]->transform.setLocalPosition(vec3(0,100,0));


		debugLine1 = "x: " + std::to_string(camera.pos.x) 
			+ " y: " + std::to_string(camera.pos.y)
			+ " z: " + std::to_string(camera.pos.z);

		debugLine2 = "wp_up: " + std::to_string(wp_up.x)
			+ " wp_right: " + std::to_string(wp_right.x)
			+ " wp_forward: " + std::to_string(wp_forward.x);

		debugLine3 = "deltaTime: " + std::to_string(Time::deltaTime())
			+ " (" + std::to_string(1 / Time::deltaTime())
			+ "fps)";


		debugLine4 = "cube1 vel x: " + std::to_string(gameobjects[1]->rigidbody->velocity.x)
			+ " y: " + std::to_string(gameobjects[1]->rigidbody->velocity.y)
			+ " z: " + std::to_string(gameobjects[1]->rigidbody->velocity.z);

		debugLine5 = "cube1 pos x: " + std::to_string(gameobjects[1]->transform.getLocalPosition().x)
			+ " y: " + std::to_string(gameobjects[1]->transform.getLocalPosition().y)
			+ " z: " + std::to_string(gameobjects[1]->transform.getLocalPosition().z);

	}

	Draw();
}

void Level01::Draw()
{
	Scene::Draw();
	graphicsHandler->drawCollage();
}
