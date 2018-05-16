#pragma once
#include "pch.h"

#include "Component.h"

class Scene;

class GameObject
{
public:
	// 모든 Object에는 기본적으로 TransformComponent가 자동적으로 추가 됩니다.
	GameObject();
	virtual ~GameObject() = default;

public:
	bool Terminate();
	void Update();
	void Draw();

	// Object의 자식을 추가 및 제거.
	void AddChild(GameObject* _child);
	void RemoveChild(GameObject* _child);
	// Object의 Component를 추가 및 제거.
	void AddComponent(Component* _com);
	void RemoveComponent(Component* _com);

	// Object가 소속된 Scene을 설정.
	void SetRelativeScene(Scene* _scene);
	// Object의 부모를 설정.
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