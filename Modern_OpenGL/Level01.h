#pragma once
#include "Scene.h"
#include "Camera.h"
#include "Skybox.h"

class Level01 :	public Scene
{
public:
	Level01();
	virtual ~Level01();

	virtual void Load();
	virtual void Update();

private:
	virtual void Draw();

	Camera camera = Camera(45, 16 / 9, 0.001, 1000);
	Skybox * skybox;

};

