#include "GameManager.h"
#include "Input.h"
#include "Time.h"
#include "MainMenu.h"

GameManager * GameManager::Instance;

GameManager::GameManager()
{
	Instance = this;
	playerHealth = 100;
	playerPoints = 0;
	targetPoints = 10;
	totalTime = 60;
}


GameManager::~GameManager()
{
}

void GameManager::GameManagerUpdate() {
	timeElapsed += Time::deltaTime();

	if (playerPoints >= targetPoints) {
		levelCompleted = true;
		won = true;
	}

	else if (timeElapsed > totalTime || playerHealth <= 0)
	{
		levelCompleted = true;
		won = false;
	}
}

void GameManager::UpdateEnemyCount() {
	switch (diff) {
	case easy:
		enemyCount = 6;
		break;
	case medium:
		enemyCount = 5;
		break;
	case hard:
		enemyCount = 4;
		break;
	}
}

void GameManager::PointIncrement() {
	playerPoints++;
}

void GameManager::Reset()
{
	timeElapsed = 0;
	playerPoints = 0;
	levelCompleted = false;
	levelStarted = false;
	won = false;
}
