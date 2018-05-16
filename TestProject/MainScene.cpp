#include "MainScene.h"

#include "../Mini2DEngine/CameraObject.h"
#include "../Mini2DEngine/ImageComponent.h"

MainScene::MainScene()
	:Scene(_T("MainScene"))
{
	object = new TestObject();
	child = new TestChildObject();
}

MainScene::~MainScene()
{
	delete object;
	delete child;
}



bool MainScene::Initialize()
{
	// 먼저 Camera를 설정합니다. 필요시 Camera를 상속해서 Customizing할 수 있습니다.
	SetCamera(new CameraObject());

	// Secne에 부모 Object를 추가합니다.
	AddGameObject(object);

	// ImageComponent를 생성합니다.
	ImageComponent* imageComponent1 = new ImageComponent();
	// ImageComponent에 Image File을 등록합니다.
	imageComponent1->ChangeImage(_T("resource/1.jpg"));
	// 부모 Object에 ImageComponent를 추가합니다.
	object->AddComponent(imageComponent1);

	// Secne에 부자식 Object를 추가합니다.
	AddGameObject(child);
	// 자식 Object를 부모 Object에 추가합니다.
	object->AddChild(child);

	// ImageComponent를 생성합니다.
	ImageComponent* imageComponent2 = new ImageComponent();
	// ImageComponent에 Image File을 등록합니다.
	imageComponent2->ChangeImage(_T("resource/2.jpg"));
	// 자식 Object에 ImageComponent를 추가합니다.
	object->AddComponent(imageComponent2);

	return true;
}