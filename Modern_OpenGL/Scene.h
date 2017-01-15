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

protected:

	virtual void Draw() = 0;
	GraphicsHandler * graphicsHandler;
	std::vector<GameObject*> gameobjects;
};

