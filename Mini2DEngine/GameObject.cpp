#include "pch.h"
#include "GameObject.h"

#include "Scene.h"
#include "CameraObject.h"
#include "GraphicsSystem.h"
#include "TransformComponent.h"

GameObject::GameObject()
{
	AddComponent(new TransformComponent());
}



bool GameObject::Terminate()
{
	if (m_components.empty() == false) {
		for (auto& a : m_components) {
			delete a;
		}
	}
	m_components.clear();

	if (m_childs.empty() == false) {
		for (auto& a : m_childs) {
			a->Terminate();
			delete a;
		}
	}
	m_childs.clear();

	return true;
}

void GameObject::Update()
{
	if (m_components.empty() == false) {
		for (auto& a : m_components) {
			a->Update();
		}
	}

	if (m_childs.empty() == false) {
		for (auto& a : m_childs) {
			a->Update();
		}
	}
}

void GameObject::Draw()
{
	Matrix3x2 worldMat = GetComponent<TransformComponent>()->GetWorldMatrix();
	Matrix3x2 viewMat = m_relativeScene->GetCamera()->GetViewMatrix();
	Matrix3x2 wvMat = worldMat * viewMat;

	GraphicsSystem::Instance()->GetRT()->SetTransform(wvMat.D2DMatrixF());

	if (m_components.empty() == false) {
		for (auto& a : m_components) {
			a->Draw();
		}
	}

	if (m_childs.empty() == false) {
		for (auto& a : m_childs) {
			a->Draw();
		}
	}

	Matrix3x2 temp;
	GraphicsSystem::Instance()->GetRT()->SetTransform(temp.D2DMatrixF());
}



void GameObject::AddChild(GameObject* _child)
{
	std::vector<GameObject*>::iterator it = std::find(m_childs.begin(), m_childs.end(), _child);
	if (it == m_childs.end()) {
		_child->SetParent(this);
		m_childs.push_back(_child);
	}
}

void GameObject::RemoveChild(GameObject* _child)
{
	std::vector<GameObject*>::iterator it = std::find(m_childs.begin(), m_childs.end(), _child);
	if (it != m_childs.end()) {
		_child->SetParent(nullptr);
		m_childs.erase(it);
	}
}

void GameObject::AddComponent(Component* _com)
{
	std::vector<Component*>::iterator it = std::find(m_components.begin(), m_components.end(), _com);
	if (it == m_components.end()) {
		_com->SetOwner(this);
		m_components.push_back(_com);
	}
}

void GameObject::RemoveComponent(Component* _com)
{
	std::vector<Component*>::iterator it = std::find(m_components.begin(), m_components.end(), _com);
	if (it != m_components.end()) {
		delete *it;
		m_components.erase(it);
	}
}



void GameObject::SetRelativeScene(Scene* _scene)
{
	m_relativeScene = _scene;
}

void GameObject::SetParent(GameObject* _parent)
{
	m_parent = _parent;
}



GameObject* GameObject::GetParent() const
{
	return m_parent;
}