#include "Level01.h"
#include "Skybox.h"

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
	gameobjects.push_back(new Cube(vec3(0, 0, 0)));
	camera.pos = vec3(0, 0, 0);

	for (int i = 0; i < 20; i+=2)
	{
		gameobjects.push_back(new Cube(vec3(i, 0, 0)));
		gameobjects.push_back(new Cube(vec3(0, i, 0)));
		gameobjects.push_back(new Cube(vec3(0, 0, i)));

	}
}

float f = 0;
void Level01::Update()
{
	vec3 newRot = gameobjects[0]->transform.getRotation();
	newRot.y = f * 10;

	vec3 newPos = gameobjects[0]->transform.getLocalPosition();
	newPos.x = glm::sin(f);

	vec3 newScale = gameobjects[0]->transform.getLocalScale();
	newScale.x = 1 + glm::sin(f) / 2;

	f += 0.001;
	gameobjects[0]->transform.setRotation(newRot);
	gameobjects[0]->transform.setLocalPosition(newPos);
	gameobjects[0]->transform.setLocalScale(newScale);

	skybox->Update(camera.pos);

	Draw();
}

void Level01::Draw()
{
	camera.UpdateCamera();
	graphicsHandler->drawCollage();
}
