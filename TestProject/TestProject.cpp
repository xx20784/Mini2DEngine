#include "TestProject.h"

#include "MainScene.h"
#include "../Mini2DEngine/SceneManager.h"

bool TestProject::BindScene()
{
	// 만들어 둔 Scene을 추가합니다.
	m_sceneManager->AddScene(new MainScene());
	// Scene을 MainScene으로 등록합니다. 반드시 MainScene은 있어야 합니다.
	m_sceneManager->SetMainScene(_T("MainScene"));

	return true;
}