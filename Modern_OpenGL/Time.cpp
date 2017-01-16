#include "Time.h"
#include <exception>
#include <Windows.h>

Time * Time::p_Instance = nullptr;

Time::Time()
{
	if (p_Instance == nullptr)
	{
		if (!QueryPerformanceFrequency(
			(LARGE_INTEGER *)&m_countsPerSecond)) {
			MessageBox(NULL, "QueryPerformanceFrequency Failed.", "ERROR", MB_OK | MB_ICONINFORMATION);
			return;
		}
		p_Instance = this;
		QueryPerformanceCounter((LARGE_INTEGER *)&p_Instance->m_startCount);
		p_Instance->m_countsLastFrame = p_Instance->m_startCount;
	}
}


Time::~Time()
{
}

float Time::time()
{
	return p_Instance->m_time;
}

float Time::deltaTime()
{
	return p_Instance->m_deltaTime;
}

float Time::update()
{
	__int64 countsThisFrame;

	QueryPerformanceCounter((LARGE_INTEGER *)&countsThisFrame);

	p_Instance->m_countsSinceStart = countsThisFrame - p_Instance->m_startCount;

	p_Instance->m_deltaTime = (countsThisFrame - p_Instance->m_countsLastFrame) / (double)p_Instance->m_countsPerSecond;

	p_Instance->m_time = (countsThisFrame - p_Instance->m_startCount) / (double)p_Instance->m_countsPerSecond;
	
	p_Instance->m_countsLastFrame = countsThisFrame;



	// Calculate fps
	if (p_Instance->m_time - p_Instance->updateSecond > 1)
	{
		p_Instance->updateSecond = p_Instance->m_time;
		p_Instance->fps = p_Instance->fpsCounter;
		p_Instance->fpsCounter = 0;
	}
	else
	{
		p_Instance->fpsCounter++;
	}

	return p_Instance->fps;
}
