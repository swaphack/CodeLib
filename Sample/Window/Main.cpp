#include <windows.h>
#include <stdio.h>


#include "resource.h"
#include "WndRender.h"

int  WINAPI WinMain(HINSTANCE	hInstance,                 // ��ǰ����ʵ��
	HINSTANCE	hPrevInstance,             // ǰһ������ʵ��
	LPSTR		lpCmdLine,                 // �����в���
	int			nCmdShow)                  // ������ʾ״̬
{

	//����̨���
	AllocConsole();
	//AttachConsole(ATTACH_PARENT_PROCESS); // ����ǰ�����ŵ���������  
	freopen("CONIN$", "r+t", stdin); // �ض��� STDIN  
	freopen("CONOUT$", "w+t", stdout); // �ض���STDOUT  

	int width = 1024;
	int height = 768;
	int bits = 32;

	render::GLFrame* frame = new render::GLFrame();
	frame->initWindow("OpenGL", width, height, bits, new WndRender());

	// ���ٴ���
	return 0;                                                                                                                           // �˳�����
}