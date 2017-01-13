#include "Level01.h"

Level01::Level01()
{
	name = "Level01";
}

Level01::~Level01()
{
}

void Level01::Load()
{
	graphicsHandler = new GraphicsHandler();
	cube = new Cube(vec3(0, 0, 0));
	camera.pos = vec3(5, 5, 5);

}

float f = 0;

void Level01::Update()
{
	//vec3 newRot = cube->transform.getRotation();
	//newRot.y = f * 10;

	//vec3 newPos = cube->transform.getLocalPosition();
	//newPos.x = glm::sin(f);

	//vec3 newScale = cube->transform.getLocalScale();
	//newScale.x = 1 + glm::sin(f) / 2;

	//f += 0.1;

	//cube->transform.setRotation(newRot);
	//cube->transform.setLocalPosition(newPos);
	//cube->transform.setLocalScale(newScale);

	Draw();
}

void Level01::Unload()
{
	delete cube;
}

void Level01::Draw()
{
	camera.UpdateCamera();
	graphicsHandler->drawCollage();
}
