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
