#include "pch.h"
#include "SceneManager.h"

#include "Scene.h"

using namespace std;

SceneManager::SceneManager()
{
	assert(!m_isCreate);
	m_isCreate = true;
}



bool SceneManager::Terminate()
{
	if (m_scenes.empty() == false) {
		for (auto& a : m_scenes) {
			a->Terminate();
			delete a;
		}
	}
	m_scenes.clear();

	return true;
}

void SceneManager::Update()
{
	assert(m_mainScene != nullptr);
	m_mainScene->Update();

	if (m_uiScene != nullptr) {
		m_uiScene->Update();
	}
}

void SceneManager::Draw()
{
	assert(m_mainScene != nullptr);
	m_mainScene->Draw();

	if (m_uiScene != nullptr) {
		m_uiScene->Draw();
	}
}



void SceneManager::AddScene(Scene* _scene)
{
	std::vector<Scene*>::iterator it = std::find(m_scenes.begin(), m_scenes.end(), _scene);
	if (it == m_scenes.end()) {
		m_scenes.push_back(_scene);
	}
}

void SceneManager::SetMainScene(const tstring& _Name)
{
	std::vector<Scene*>::iterator it = std::find_if(m_scenes.begin(), m_scenes.end(), [_Name](Scene* scene) -> bool { return scene->GetName() == _Name; });
	assert(it != m_scenes.end());

	if (m_mainScene != nullptr) {
		m_mainScene->SetIsActive(false);
	}

	m_mainScene = (*it);
	m_mainScene->SetIsActive(true);
	m_mainScene->Initialize();
}

void SceneManager::SetUIScene(const tstring& _Name)
{
	std::vector<Scene*>::iterator it = std::find_if(m_scenes.begin(), m_scenes.end(), [_Name](Scene* scene) -> bool { return scene->GetName() == _Name; });
	assert(it != m_scenes.end());

	if (m_uiScene != nullptr) {
		m_uiScene->SetIsActive(false);
	}

	m_uiScene = (*it);
	m_uiScene->SetIsActive(true);
	m_uiScene->Initialize();
}

bool SceneManager::m_isCreate = false;