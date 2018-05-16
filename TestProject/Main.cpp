#include "TestProject.h"
#include "../Mini2DEngine/Engine.h"

#if defined (DEBUG) | defined(_DEBUG)
int _tmain(int argc, char* argv[])
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	WinMain((HINSTANCE)GetModuleHandle(NULL), 0, 0, SW_SHOW);
}
#endif

int WINAPI WinMain(HINSTANCE _hInst, HINSTANCE _hPreInst, LPSTR _lpCmdLine, int _nCmdShow)
{
	UNREFERENCED_PARAMETER(_hInst);
	UNREFERENCED_PARAMETER(_hPreInst);
	UNREFERENCED_PARAMETER(_lpCmdLine);
	UNREFERENCED_PARAMETER(_nCmdShow);

#if defined (DEBUG) | defined(_DEBUG)
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
#endif

	// New Project를 등록하는 것으로 Engine을 실행합니다.
	Engine engine(new TestProject());
	int result = engine.MainLoop();

	/*Git 연동 Test*/

	return result;
}