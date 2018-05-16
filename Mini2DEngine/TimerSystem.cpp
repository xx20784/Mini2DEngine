#include "pch.h"
#include "TimerSystem.h"

Timer::Timer()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	m_cpuTickDelta = 1.0 / static_cast<double>(frequency.QuadPart);

	Start();
}



void Timer::Start()
{
	LARGE_INTEGER currentTick;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTick);
	m_preTime = currentTick.QuadPart;

	if (m_isStop) {
		m_pauseTime += (currentTick.QuadPart - m_stopTime);

		m_stopTime = 0;
		m_isStop = false;
	}
}

void Timer::Stop()
{
	if (!m_isStop) {
		LARGE_INTEGER currentTick;
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTick);

		m_stopTime = currentTick.QuadPart;
		m_isStop = true;
	}
}

void Timer::Update()
{
	if (m_isStop) {
		m_dt = 0.0;
	}

	LARGE_INTEGER currentTick;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTick);
	m_curTime = currentTick.QuadPart;
	m_dt = (m_curTime - m_preTime) * m_cpuTickDelta;
	m_preTime = m_curTime;

	if (m_dt < 0.0) {
		m_dt = 0.0;
	}
}

void Timer::Reset()
{
	LARGE_INTEGER currentTick;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTick);

	m_startTime = currentTick.QuadPart;
	m_preTime = currentTick.QuadPart;
	m_stopTime = 0;

	m_isStop = false;
}



float Timer::GetTotalTime() const
{
	if (m_isStop) {
		return static_cast<float>((m_stopTime - m_startTime) * m_cpuTickDelta);
	}
	return static_cast<float>(((m_curTime - m_pauseTime) - m_startTime) * m_cpuTickDelta);
}

float Timer::GetDeltaTime() const
{
	return static_cast<float>(m_dt);
}





TimerSystem::TimerSystem()
{
	assert(!m_isCreate);
	m_isCreate = true;
}



bool TimerSystem::Initialize()
{
	m_timer = new Timer();

	return true;
}

bool TimerSystem::Terminate()
{
	delete m_timer;

	return true;
}

void TimerSystem::Update()
{
	m_timer->Update();
}

bool TimerSystem::m_isCreate = false;