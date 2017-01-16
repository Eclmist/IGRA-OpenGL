#pragma once

class Time
{
public:
	Time();
	~Time();

public:
	static float time();
	static float deltaTime();

	static float update();
public:
	static Time* p_Instance;

private:
	__int64 m_countsPerSecond;

	__int64 m_countsLastFrame;
	__int64 m_countsSinceStart;
	__int64 m_startCount;

	double m_deltaTime = 0;
	double m_time = 0;

private:
	//fps

	double updateSecond = 0;
	float fps = 0;
	float fpsCounter = 0;
};

