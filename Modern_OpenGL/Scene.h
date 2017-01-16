#pragma once
#include "Mesh.h"
#include "GraphicsHandler.h"
#include "Cube.h"

class Scene
{
public:

	Scene();
	virtual ~Scene();

	virtual void Load() = 0;
	virtual void Update() = 0;
	virtual void Unload();

	std::string name;
	bool sceneDebug = false;

protected:

	virtual void Draw();
	GraphicsHandler * graphicsHandler;
	std::vector<GameObject*> gameobjects;

	virtual void DrawDebugInfo();
	void DrawAxisSystem();

};

