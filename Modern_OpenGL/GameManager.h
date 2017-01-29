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
	void PointIncrement();
	void UpdateEnemyCount();

	Difficulty diff;
	int enemyCount;

	void Reset();

	int playerHealth;
	int playerPoints;
	int targetPoints;

	float timeElapsed;
	float totalTime;

	bool levelCompleted = false;
	bool levelStarted = false;
	bool won = false;

	static GameManager* Instance;
};

