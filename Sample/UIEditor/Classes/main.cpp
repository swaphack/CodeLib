#include <windows.h>
#include <cstdio>
#include <string>

//#include <vld.h>

#include "system.h"
#include "render.h"
#include "UIEditorApplication.h"

using namespace ue;

int main(int argc, char** argv)                  // 窗口显示状态
{
	//控制台输出
	//AllocConsole();
	//AttachConsole(ATTACH_PARENT_PROCESS); // 将当前程序附着到父进程上  
	//freopen("CONIN$", "rt", stdin); // 重定向 STDIN  
	//freopen("CONOUT$", "wt", stdout); // 重定向STDOUT  
	/*
	G_CONSOLELISTENER->setReceiveLineCallback([](const std::string& line) {
		std::string command = line;
	});
	G_CONSOLELISTENER->run();
	*/
	int width = 1366;
	int height = 960;
	int millis = 17;

	render::GLWindow* pWindow = new render::GLWindow();
	pWindow->createWindow("UIEditor", width, height, millis, new UIEditorApplication());

	return 0;
}