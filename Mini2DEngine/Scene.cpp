#include "pch.h"
#include "Scene.h"

#include "GameObject.h"
#include "CameraObject.h"

using namespace std;

Scene::Scene(const tstring& name)
	:m_name(name)
{}



bool Scene::Terminate()
{
	m_camera->Terminate();
	delete m_camera;

	if (m_objects.empty() == false) {
		for (auto& a : m_objects) {
			a->Terminate();
			delete a;
		}
	}
	m_objects.clear();

	return true;
}

void Scene::Update()
{
	if (m_camera == nullptr || m_objects.empty() == true) {
		return;
	}

	m_camera->Update();

	for (auto& a : m_objects) {
		a->Update();
	}
}

void Scene::Draw()
{
	if (m_objects.empty() == false) {
		for (auto& a : m_objects) {
			a->Draw();
		}
	}
}



void Scene::AddGameObject(GameObject* _object)
{
	std::vector<GameObject*>::iterator it = find(m_objects.begin(), m_objects.end(), _object);
	if (it == m_objects.end()) {
		_object->SetRelativeScene(this);
		m_objects.push_back(_object);
	}
}

void Scene::RemoveGameObject(GameObject* _object)
{
	std::vector<GameObject*>::iterator it = find(m_objects.begin(), m_objects.end(), _object);
	if (it != m_objects.end()) {
		(*it)->Terminate();
		delete *it;
		m_objects.erase(it);
	}
}



void Scene::SetIsActive(bool _isActivate)
{
	m_isActive = _isActivate;
}

void Scene::SetCamera(CameraObject* _camera)
{
	m_camera = _camera;
}



bool Scene::GetIsActive() const
{
	return m_isActive;
}

const CameraObject* Scene::GetCamera() const
{
	return m_camera;
}

const std::tstring& Scene::GetName() const
{
	return m_name;
}