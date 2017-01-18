#include "GameManager.h"
#include "Input.h"

GameManager::GameManager()
{
	playerHealth = 100;
	playerPoints = 0;
	timeLeft = 60;
}


GameManager::~GameManager()
{
}

void GameManager::GameManagerUpdate() {
	if (playerPoints >= 45) {
		completeLevel = true;
	}

	if (completeLevel == true && Input::getKey('F')) {
		//Runs next Scene
		//Do not use spacebar for GetKeyDown as player might need to jump
		completeLevel = false;
		timeLeft = 60;
	}

	switch (completeLevel) {
	case true:
		if (timeLeft <= 0) {
			//Runs next Scene
		}
		break;
	case false:
		if (timeLeft <= 0 || playerHealth <= 0) {
			EndGame();
		}
	}
}

void GameManager::PointIncrement() {
	playerPoints++;
}

void GameManager::EndGame() {
	// End Game
}