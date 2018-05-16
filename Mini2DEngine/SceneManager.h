#pragma once
#include "pch.h"

class Scene;

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager() = default;

public:
	bool Terminate();
	// Main Scene은 반드시 있어야 Update와 Draw를 합니다.
	void Update();
	void Draw();

	// Game 내 사용될 Scene들을 추가.
	void AddScene(Scene* _scene);
	// Main Scene 활성화.
	void SetMainScene(const std::tstring& _name);
	// UI Scene 활성화.
	void SetUIScene(const std::tstring& _name);

private:
	std::vector<Scene*> m_scenes;
	Scene* m_mainScene = nullptr;
	Scene* m_uiScene = nullptr;

private:
	// 한 객체만 생성됩니다.
	static bool m_isCreate;
};