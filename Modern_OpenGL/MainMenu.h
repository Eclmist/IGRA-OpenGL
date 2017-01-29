/*
Written by: Ivan Leong Jit Kiong
Admin No: p1548268
*/


#pragma once
#include "Scene.h"
#include "Camera.h"
#include "Skybox.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "GameManager.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	virtual ~MainMenu();

	virtual void Load();
	virtual void Update();

	void DrawMainMenu();
	void CheckInput();

	std::string difficultyText;
	std::string difficultyEasy = "Difficulty: Easy";
	std::string difficultyMed = "Difficulty: Medium";
	std::string difficultyHard = "Difficulty: Hard";

	std::string creditLine1 = "Game Developers:";
	std::string creditLine2 = "Samuel Huang Hao Yi     p1500176";
	std::string creditLine3 = "Ivan Leong Jit Kiong     p1548268";
	std::string creditLine4 = "Class: DIT/FT/2B/05";
private:
	virtual void Draw();
	void PrintCredits(int);

	bool creditsEnabled = false;

	Skybox * skybox;

	std::vector<Enemy*> enemyobjects;
};

