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
	totalTime = 60;
}


GameManager::~GameManager()
{
}

void GameManager::GameManagerUpdate() {
	timeElapsed += Time::deltaTime();

	if (playerPoints >= 45) {
		levelCompleted = true;
		EndGame(true);
	}

	else if (timeElapsed > totalTime || playerHealth <= 0)
	{
		levelCompleted = true;
		EndGame(false);
	}
}

void GameManager::UpdateEnemyCount() {
	switch (diff) {
	case easy:
		enemyCount = 12;
		break;
	case medium:
		enemyCount = 7;
		break;
	case hard:
		enemyCount = 4;
		break;
	}
}

void GameManager::PointIncrement() {
	playerPoints++;
}

void GameManager::EndGame(bool won) {
	// End Game
}