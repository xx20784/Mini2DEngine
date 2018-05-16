#pragma once
#include "pch.h"

class SceneManager;

class Project
{
public:
	virtual	~Project() = default;

public:
	virtual bool BindScene() = 0;
	void SetSceneManager(SceneManager* _scenemanager);

protected:
	SceneManager* m_sceneManager = nullptr;
};