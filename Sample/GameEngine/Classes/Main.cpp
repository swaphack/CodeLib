#include <windows.h>
#include <cstdio>
#include <string>

//#include <vld.h>

#include "system.h"
#include "render.h"
#include "GLRenderApplication.h"

using namespace sys;

int main(int argc, char** argv)                  // 窗口显示状态
{
	/*
	//控制台输出
	AllocConsole();
	//AttachConsole(ATTACH_PARENT_PROCESS); // 将当前程序附着到父进程上  
	freopen("CONIN$", "rt", stdin); // 重定向 STDIN  
	freopen("CONOUT$", "wt", stdout); // 重定向STDOUT  
	
	G_CONSOLELISTENER->setReceiveLineCallback([](const std::string& line) {
		std::string command = line;
	});
	G_CONSOLELISTENER->run();
	*/
	int width = 1024;
	int height = 768;
	int millis = 17;

	render::GLWindow* pWindow = new render::GLWindow();
	pWindow->createWindow("OpenGL", width, height, millis, new GLRenderApplication());

	return 0;                                                                                                                          
}