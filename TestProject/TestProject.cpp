#include "TestProject.h"

#include "MainScene.h"
#include "../Mini2DEngine/SceneManager.h"

bool TestProject::BindScene()
{
	// ����� �� Scene�� �߰��մϴ�.
	m_sceneManager->AddScene(new MainScene());
	// Scene�� MainScene���� ����մϴ�. �ݵ�� MainScene�� �־�� �մϴ�.
	m_sceneManager->SetMainScene(_T("MainScene"));

	return true;
}