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
	camera.pos = vec3(0, 0, 0);

	gameobjects.push_back(new Cube(vec3(0, 0, 0)));
	gameobjects[1]->transform.setLocalScale(vec3(0.01));

	gameobjects.push_back(new Level01Prefab(vec3(0, 0, 0)));

}

float f = 0;

vec3 right;
vec3 forward;
vec3 up;
void Level01::Update()
{
	camera.UpdateCamera();
	skybox->Update(camera.pos);


	vec3 awpTargetPos = camera.pos - camera.right * right + camera.dir * forward - (camera.up * up);

	vec3 lerpVector = awpTargetPos - gameobjects[0]->transform.getLocalPosition();

	gameobjects[0]->transform.setLocalPosition(gameobjects[0]->transform.getLocalPosition() + lerpVector *
		vec3(Time::deltaTime() * 30));
	gameobjects[0]->transform.setRotation(vec3(-camera.pitch, -camera.yaw + 90, 0));

	if (Input::getKeyDown('T'))
		sceneDebug = !sceneDebug;

	if (sceneDebug)
	{
		if (Input::getKey('I')) up += vec3(0.01F);
		if (Input::getKey('L')) right += vec3(0.01F);
		if (Input::getKey('J')) right -= vec3(0.01F);
		if (Input::getKey('K')) up -= vec3(0.01F);

		if (Input::getKey('U')) forward += vec3(0.01F);
		if (Input::getKey('O')) forward -= vec3(0.01F);
	}

	Draw();
}

void Level01::Draw()
{
	Scene::Draw();
	graphicsHandler->drawCollage();
}
