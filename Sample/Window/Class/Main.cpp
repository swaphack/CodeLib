#include <windows.h>
#include <cstdio>
#include <string>

#include "system.h"
#include "render.h"
#include "GLRenderApplication.h"

using namespace sys;

int  WINAPI WinMain(HINSTANCE	hInstance,                 // ��ǰ����ʵ��
	HINSTANCE	hPrevInstance,             // ǰһ������ʵ��
	LPSTR		lpCmdLine,                 // �����в���
	int			nCmdShow)                  // ������ʾ״̬
{

	//����̨���
	AllocConsole();
	//AttachConsole(ATTACH_PARENT_PROCESS); // ����ǰ�����ŵ���������  
	freopen("CONIN$", "rt", stdin); // �ض��� STDIN  
	freopen("CONOUT$", "wt", stdout); // �ض���STDOUT  

	G_CONSOLELISTENER->setReceiveLineCallback([](const std::string& line) {
		std::string command = line;
	});
	G_CONSOLELISTENER->run();

	int width = 1024;
	int height = 768;
	int millis = 17;

	render::GLWindow* pWindow = new render::GLWindow();
	pWindow->createWindow("OpenGL", width, height, millis, new GLRenderApplication());

	return 0;                                                                                                                          
}