#pragma once
#include "pch.h"

class GameObject;
class CameraObject;

class Scene
{
public:
	Scene(const std::tstring& name);
	virtual ~Scene() = default;

	virtual bool Initialize() = 0;
	virtual bool Terminate();
	virtual void Update();
	virtual void Draw();

	// Scene에서 사용할 Object를 추가 및 제거.
	void AddGameObject(GameObject* _object);
	void RemoveGameObject(GameObject* _object);

	// 활성화 여부 설정.
	void SetIsActive(bool _isActivate);
	// Camera(View) 설정.
	void SetCamera(CameraObject* _camera);

	// Get Method.
	bool GetIsActive() const;
	const CameraObject* GetCamera() const;
	const std::tstring& GetName() const;

protected:
	std::vector<GameObject*> m_objects;
	CameraObject* m_camera = nullptr;

	std::tstring m_name;
	bool m_isActive = false;
};