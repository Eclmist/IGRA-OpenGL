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
