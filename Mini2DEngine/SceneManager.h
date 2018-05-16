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
	// Main Scene�� �ݵ�� �־�� Update�� Draw�� �մϴ�.
	void Update();
	void Draw();

	// Game �� ���� Scene���� �߰�.
	void AddScene(Scene* _scene);
	// Main Scene Ȱ��ȭ.
	void SetMainScene(const std::tstring& _name);
	// UI Scene Ȱ��ȭ.
	void SetUIScene(const std::tstring& _name);

private:
	std::vector<Scene*> m_scenes;
	Scene* m_mainScene = nullptr;
	Scene* m_uiScene = nullptr;

private:
	// �� ��ü�� �����˴ϴ�.
	static bool m_isCreate;
};