#pragma once
#include "../Mini2DEngine/Scene.h"
#include "../Mini2DEngine/GameObject.h"

class TestObject : public GameObject
{};

class TestChildObject : public GameObject
{};





class MainScene : public Scene
{
public:
	MainScene();
	virtual ~MainScene();

	virtual bool Initialize() override;

private:
	TestObject* object = nullptr;
	TestChildObject* child = nullptr;
};