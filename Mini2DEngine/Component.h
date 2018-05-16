#pragma once
#include "pch.h"

class GameObject;

class Component
{
public:
	virtual ~Component() = default;

public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// Component�� �Ҽӵ� Object�� ����.
	void SetOwner(GameObject* _owner);

	// Get Method.
	GameObject* GetOwner() const;

protected:
	GameObject* m_owner = nullptr;
};