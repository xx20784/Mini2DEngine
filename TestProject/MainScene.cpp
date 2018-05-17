#include "MainScene.h"

#include "../Mini2DEngine/CameraObject.h"
#include "../Mini2DEngine/ImageComponent.h"
#include "../Mini2DEngine/TransformComponent.h"

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

	// Secne�� �ڽ� Object�� �߰��մϴ�.
	AddGameObject(child);
	// Secne�� �θ� Object�� �߰��մϴ�.
	AddGameObject(object);

	// ImageComponent�� �����մϴ�.
	ImageComponent* imageComponent1 = new ImageComponent();
	// ImageComponent�� Image File�� ����մϴ�.
	imageComponent1->ChangeImage(_T("resource/1.png"));
	// �θ� Object�� ImageComponent�� �߰��մϴ�.
	object->AddComponent(imageComponent1);

	// ImageComponent�� �����մϴ�.
	ImageComponent* imageComponent2 = new ImageComponent();
	// ImageComponent�� Image File�� ����մϴ�.
	imageComponent2->ChangeImage(_T("resource/2.png"));
	// �ڽ� Object�� ImageComponent�� �߰��մϴ�.
	child->AddComponent(imageComponent2);

	// �ڽ� Object�� �θ� Object�� �߰��մϴ�.
	object->AddChild(child);

	object->GetComponent<TransformComponent>()->Translate(10.0f, 10.0f);
	child->GetComponent<TransformComponent>()->Translate(60.0f, 60.0f);
	
	return true;
}