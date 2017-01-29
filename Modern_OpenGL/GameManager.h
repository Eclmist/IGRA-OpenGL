#pragma once
enum Difficulty {
	easy,
	medium,
	hard
};

class GameManager
{
public:
	GameManager();
	~GameManager();

	void GameManagerUpdate();
	void EndGame(bool won);
	void PointIncrement();
	void UpdateEnemyCount();

	Difficulty diff;
	int enemyCount;

	int playerHealth;
	int playerPoints;
	float timeElapsed;
	float totalTime;

	bool levelCompleted = false;
	bool levelStarted = false;

	static GameManager* Instance;
};

