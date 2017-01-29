#pragma once
#include "Scene.h"
#include "Camera.h"
#include "Skybox.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"

enum Difficulty {
	easy,
	medium,
	hard
};

class MainMenu : public Scene
{
public:
	MainMenu();
	virtual ~MainMenu();

	virtual void Load();
	virtual void Update();

	void DrawMainMenu();
	void CheckInput();

	Difficulty diff = easy;

	std::string difficulty;
	std::string difficultyEasy = "Difficulty: Easy";
	std::string difficultyMed = "Difficulty: Medium";
	std::string difficultyHard = "Difficulty: Hard";

	std::string creditLine1, creditLine2,
		creditLine3, creditLine4;

private:
	virtual void Draw();

	bool creditsEnabled = false;

	Skybox * skybox;

	std::vector<Enemy*> enemyobjects;
};

