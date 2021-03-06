#pragma once
#include "pch.h"

class Project;
class TimerSystem;
class SceneManager;
class WindowSystem;

// System들을 통해 Engine을 구동하는 Main Class.
class Engine
{
public:
	Engine(Project* _project);
	~Engine() = default;

public:
	int MainLoop();

private:
	bool Initialize();
	bool Terminate();
	void Update();
	void Draw();

private:
	Project* m_project = nullptr;

	TimerSystem* m_timer = nullptr;
	WindowSystem*  m_window = nullptr;
	SceneManager* m_sceneManager = nullptr;

	// 한 객체만 생성됩니다.
	static bool m_isCreate;
};