#include <windows.h>
#include <stdio.h>
#include "App.h"

//using namespace sys;

int  WINAPI WinMain(HINSTANCE	hInstance,                 // 当前窗口实例
	HINSTANCE	hPrevInstance,             // 前一个窗口实例
	LPSTR		lpCmdLine,                 // 命令行参数
	int			nCmdShow)                  // 窗口显示状态
{

	//控制台输出
	AllocConsole();
	//AttachConsole(ATTACH_PARENT_PROCESS); // 将当前程序附着到父进程上  
	freopen("CONIN$", "rt", stdin); // 重定向 STDIN  
	freopen("CONOUT$", "wt", stdout); // 重定向STDOUT  

	int width = 1024;
	int height = 768;
	int bits = 32;

	render::GLFrame* frame = new render::GLFrame();
	frame->initWindow("OpenGL", width, height, bits, new App());

	// 销毁窗口
	return 0;                                                                                                                           // 退出程序
}