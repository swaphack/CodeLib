#include <windows.h>
#include <stdio.h>

#include "resource.h"
#include "WndRender.h"

//using namespace sys;

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
	int bits = 32;

	render::GLFrame* frame = new render::GLFrame();
	frame->initWindow("OpenGL", width, height, bits, new WndRender());

	// ���ٴ���
	return 0;                                                                                                                           // �˳�����
}