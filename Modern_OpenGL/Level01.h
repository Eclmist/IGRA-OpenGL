#pragma once
#include "Scene.h"
#include "Camera.h"
#include "Skybox.h"
#include "Player.h"
#include "Enemy.h"
#include "GameManager.h"

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
	void DrawProgressBar(float timeRemaining);
	void DrawScoreText(int currentScore, int targetScore);
	void DrawEndGameText(bool won);

	Skybox * skybox;
	Player * player;
	GameManager * gameManager;

	std::vector<Enemy*> enemyobjects;
};

