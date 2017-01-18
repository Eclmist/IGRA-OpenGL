#pragma once
#include "Scene.h"
#include "Camera.h"
#include "Skybox.h"
#include "Player.h"

class Level01 :	public Scene
{
public:
	Level01();
	virtual ~Level01();

	virtual void Load();
	virtual void Update();

private:
	virtual void Draw();

	Skybox * skybox;
	Player * player;

	std::vector<Enemy*> enemyobjects;
};

