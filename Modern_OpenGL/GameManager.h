#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();

	void GameManagerUpdate();
	void EndGame();
	void PointIncrement();

	int playerHealth;
	int playerPoints;
	int timeLeft;

	bool completeLevel = false;
};

