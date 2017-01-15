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
	gameobjects.push_back(new Cube(vec3(0, 0, 0)));
	camera.pos = vec3(0, 0, 0);
	gameobjects.push_back(new Cube(vec3(-5, -1, 3)));
	gameobjects.push_back(new Cube(vec3(6, -1, 5)));
	gameobjects.push_back(new Cube(vec3(4, -1, -6)));
	gameobjects.push_back(new Cube(vec3(-3, -1, 2)));
	gameobjects.push_back(new Cube(vec3(0, -1, 2)));

}

float f = 0;
int i = 0;
void Level01::Update()
{
	vec3 newRot = gameobjects[0]->transform.getRotation();
	//newRot.y = f * 10;

	vec3 newPos = gameobjects[0]->transform.getLocalPosition();
	newPos.x = glm::sin(f);

	vec3 newScale = gameobjects[0]->transform.getLocalScale();
	//newScale.x = 1 + glm::sin(f) / 2;

	f += 0.001;
	i++;
	gameobjects[i % gameobjects.size()]->transform.setRotation(newRot);
	gameobjects[i % gameobjects.size()]->transform.setLocalPosition(newPos * vec3(i % gameobjects.size(), i % gameobjects.size(), i % gameobjects.size()));
	gameobjects[i % gameobjects.size()]->transform.setLocalScale(newScale);

	Draw();
}

void Level01::Draw()
{
	camera.UpdateCamera();
	graphicsHandler->drawCollage();
}
