#pragma once
#include "pch.h"

class Timer
{
public:
	Timer();

public:
	void Start();
	void Stop();
	void Update();
	void Reset();

	float GetTotalTime() const;
	float GetDeltaTime() const;

private:
	double m_cpuTickDelta = 0.0;
	double m_dt = -1.0;

	int64_t m_preTime = 0;
	int64_t m_curTime = 0;
	int64_t m_startTime = 0;
	int64_t m_stopTime = 0;
	int64_t m_pauseTime = 0;

	bool m_isStop = false;
};





class TimerSystem
{
public:
	TimerSystem();

public:
	bool Initialize();
	bool Terminate();
	void Update();

private:
	Timer* m_timer = nullptr;

private:
	// 한 객체만 생성됩니다.
	static bool m_isCreate;
};