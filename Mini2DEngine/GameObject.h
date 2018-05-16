#pragma once
#include "pch.h"

#include "Component.h"

class Scene;

class GameObject
{
public:
	// ��� Object���� �⺻������ TransformComponent�� �ڵ������� �߰� �˴ϴ�.
	GameObject();
	virtual ~GameObject() = default;

public:
	bool Terminate();
	void Update();
	void Draw();

	// Object�� �ڽ��� �߰� �� ����.
	void AddChild(GameObject* _child);
	void RemoveChild(GameObject* _child);
	// Object�� Component�� �߰� �� ����.
	void AddComponent(Component* _com);
	void RemoveComponent(Component* _com);

	// Object�� �Ҽӵ� Scene�� ����.
	void SetRelativeScene(Scene* _scene);
	// Object�� �θ� ����.
	void SetParent(GameObject* _parent);

	// Get Method.
	GameObject* GetParent() const;
	template <typename T> T* GetComponent() const;


protected:
	std::vector<Component*> m_components;
	std::vector<GameObject*> m_childs;
	Scene* m_relativeScene = nullptr;
	GameObject* m_parent = nullptr;
};

template <typename T>
T* GameObject::GetComponent() const
{
	for (auto& a : m_components) {
		T* temp = dynamic_cast<T*>(a);
		if (temp == nullptr) {
			continue;
		}
		return temp;
	}
	return nullptr;
}