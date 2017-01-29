#pragma once
#include "Scene.h"
#include "Camera.h"
#include "Skybox.h"
#include "Player.h"
#include "Enemy.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	virtual ~MainMenu();

	virtual void Load();
	virtual void Update();

	void DrawMainMenu();

private:
	virtual void Draw();

	Skybox * skybox;
	Player * player;

	std::vector<Enemy*> enemyobjects;
};

