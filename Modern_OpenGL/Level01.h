#pragma once
#include "Scene.h"
#include "Camera.h"

class Level01 :	public Scene
{
public:
	Level01();
	virtual ~Level01();

	virtual void Load();
	virtual void Update();
	virtual void Unload();

private:
	virtual void Draw();

	Camera camera = Camera(45, 16 / 9, 0.001, 1000);

	Cube * cube;


};

