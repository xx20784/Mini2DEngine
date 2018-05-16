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
	// ���� Camera�� �����մϴ�. �ʿ�� Camera�� ����ؼ� Customizing�� �� �ֽ��ϴ�.
	SetCamera(new CameraObject());

	// Secne�� �θ� Object�� �߰��մϴ�.
	AddGameObject(object);

	// ImageComponent�� �����մϴ�.
	ImageComponent* imageComponent1 = new ImageComponent();
	// ImageComponent�� Image File�� ����մϴ�.
	imageComponent1->ChangeImage(_T("resource/1.jpg"));
	// �θ� Object�� ImageComponent�� �߰��մϴ�.
	object->AddComponent(imageComponent1);

	// Secne�� ���ڽ� Object�� �߰��մϴ�.
	AddGameObject(child);
	// �ڽ� Object�� �θ� Object�� �߰��մϴ�.
	object->AddChild(child);

	// ImageComponent�� �����մϴ�.
	ImageComponent* imageComponent2 = new ImageComponent();
	// ImageComponent�� Image File�� ����մϴ�.
	imageComponent2->ChangeImage(_T("resource/2.jpg"));
	// �ڽ� Object�� ImageComponent�� �߰��մϴ�.
	object->AddComponent(imageComponent2);

	return true;
}