#include "Scene.h"
#include "SceneManager.h"

Scene::Scene()
{
	graphicsHandler = new GraphicsHandler();
}

Scene::~Scene()
{
	delete graphicsHandler;
}

void Scene::Unload()
{
	for (auto it = gameobjects.begin(); it != gameobjects.end(); ++it) {
		delete *it;
	}
	gameobjects.clear();
}

void Scene::Draw()
{
	if (sceneDebug)
	{
		DrawDebugInfo();
	}
}

void Scene::DrawDebugInfo()
{
	DrawAxisSystem();
}

void Scene::DrawAxisSystem()
{
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 10, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, -10);
	glColor3f(1, 1, 1);

	glEnd();
}
