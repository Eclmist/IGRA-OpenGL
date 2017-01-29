#pragma once
class GameManager
{
public:
	GameManager();
	~GameManager();

	void GameManagerUpdate();
	void EndGame(bool won);
	void PointIncrement();

	int playerHealth;
	int playerPoints;
	float timeElapsed;
	float totalTime;

	bool levelCompleted = false;
	bool levelStarted = false;

	static GameManager* Instance;
};

