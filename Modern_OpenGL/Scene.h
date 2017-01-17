#pragma once
#include "Mesh.h"
#include "GraphicsHandler.h"
#include "GameObject.h"


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

	bool loaded = false;

	float debugStringXPos = -0.71F;
	float debugStringYPos = 0.37F;

	std::string debugLine1, debugLine2,
		debugLine3, debugLine4,
		debugLine5, debugLine6,
		debugLine7, debugLine8,
		debugLine9, debugLine10,
		debugLine11, debugLine12;

private:
	void PrintLine(int);
};

