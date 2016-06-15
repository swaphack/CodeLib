/*
#include <windows.h>
#include <stdio.h>

#include "resource.h"

#include "WndWeb.h"
#include "WndRender.h"


int WINDOW_SIZE_WIDTH = 1024;
int WINDOW_SIZE_HEIGHT = 768;
const char* WEB_IP = "127.0.0.1";
int WEB_PORT = 9547;


WndRender*		wndRender=NULL;
WndWeb*			wndWeb = NULL;
HGLRC           hRC=NULL;		// 窗口着色描述表句柄
HDC             hDC=NULL;		// OpenGL渲染描述表句柄
HWND            hWnd=NULL;		// 保存我们的窗口句柄
HINSTANCE       hInstance;		// 保存程序的实例


bool            keys[256];				// 保存键盘按键的数组
bool            active=TRUE;            // 窗口的活动标志，缺省为TRUE
bool            fullscreen=TRUE;        // 全屏标志缺省，缺省设定成全屏模式
float           rtri;					// 用于几何体旋转的角度

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);   // WndProc的定义

// 正常销毁窗口
void KillGLWindow()      
{
	if (fullscreen)	// 我们处于全屏模式吗?
	{
		ChangeDisplaySettings(NULL,0);	// 是的话，切换回桌面，因为全屏模式直接关闭窗口，可能引发错误
		ShowCursor(TRUE);				// 显示鼠标指针
	}
	if (hRC)	// 我们拥有OpenGL渲染描述表吗?
	{
		if (!wglMakeCurrent(NULL,NULL))	// 我们能否释放DC和RC描述表?
		{
			MessageBox(NULL,TEXT("释放DC或RC失败。"),TEXT("关闭错误"),MB_OK | MB_ICONINFORMATION);
		}
		if (!wglDeleteContext(hRC))	// 我们能否删除RC?
		{
			MessageBox(NULL,TEXT("释放RC失败。"),TEXT("关闭错误"),MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;	// 将RC设为 NULL
	}
	if (hDC && !ReleaseDC(hWnd,hDC))	// 我们能否释放 DC?
	{
		MessageBox(NULL,TEXT("释放DC失败。"),TEXT("关闭错误"),MB_OK | MB_ICONINFORMATION);
		hDC=NULL;	// 将 DC 设为 NULL
	}
	if (hWnd && !DestroyWindow(hWnd))	// 能否销毁窗口?
	{
		MessageBox(NULL,TEXT("释放窗口句柄失败。"),TEXT("关闭错误"),MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;	// 将 hWnd 设为 NULL
	}
	if (!UnregisterClass(TEXT("OpenGL"),hInstance))	// 能否注销类?
	{
		MessageBox(NULL,TEXT("不能注销窗口类。"),TEXT("关闭错误"),MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;	// 将 hInstance 设为 NULL
	}
}

LPCWCHAR getWCHAR(char* szStr)
{
	WCHAR wszClassName[256];
	memset(wszClassName,0,sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP,0,szStr,strlen(szStr)+1,wszClassName,
		sizeof(wszClassName)/sizeof(wszClassName[0]));

	return wszClassName;
}

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	//我们要求Windows为我们寻找相匹配的象素格式时，Windows寻找结束后将模式值保存在变量PixelFormat中
	GLuint PixelFormat;			// 保存查找匹配的结果
	WNDCLASS sys;				// 窗口类结构
	DWORD dwExStyle;			// 扩展窗口风格
	DWORD dwStyle;				// 窗口风格
	RECT WindowRect;			// 取得矩形的左上角和右下角的坐标值

	WindowRect.left=(long)0;			// 将Left   设为 0
	WindowRect.right=(long)width;       // 将Right 设为要求的宽度
	WindowRect.top=(long)0;             // 将Top    设为 0
	WindowRect.bottom=(long)height;     // 将Bottom 设为要求的高度

	fullscreen = fullscreenflag;				// 设置全局全屏标志
	hInstance = GetModuleHandle(NULL);          // 取得我们窗口的实例

	sys.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// 移动时重画，并为窗口取得DC，CS_OWNDC为窗口创建一个私有的DC。这意味着DC不能在程序间共享。
	sys.lpfnWndProc = (WNDPROC) WndProc;             // WndProc处理消息
	sys.cbClsExtra = 0;                              // 无额外窗口数据
	sys.cbWndExtra = 0;                              // 无额外窗口数据
	sys.hInstance = hInstance;						// 设置实例
	sys.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// 装入缺省图标
	sys.hCursor  = LoadCursor(NULL, IDC_ARROW);		// 装入默认鼠标指针
	sys.hbrBackground = NULL;                        // GL不需要背景
	sys.lpszMenuName  = NULL;                        // 不需要菜单
	sys.lpszClassName = TEXT("OpenGL");              // 设定类名字

	if (!RegisterClass(&sys))	// 尝试注册窗口类
	{
		MessageBox(NULL,TEXT("注册窗口失败"),TEXT("错误"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// 退出并返回FALSE
	}
	if (fullscreen)	// 要尝试全屏模式吗?
	{
		DEVMODE dmScreenSettings;								// 设备模式
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// 确保内存清空为零
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);     // Devmode 结构的大小
		dmScreenSettings.dmPelsWidth = width;                   // 所选屏幕宽度
		dmScreenSettings.dmPelsHeight = height;                 // 所选屏幕高度
		dmScreenSettings.dmBitsPerPel = bits;					// 每象素所选的色彩深度                    
		//dmScreenSettings.dmFields = DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;
		// 尝试设置显示模式并返回结果。注: CDS_FULLSCREEN 移去了状态条。
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// 若模式失败，提供两个选项：退出或在窗口内运行。
			if (MessageBox(NULL,TEXT("全屏模式在当前显卡上设置失败！\n使用窗口模式？"),TEXT("NeHe G"),MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;// 选择窗口模式(Fullscreen=FALSE)
			}
			else
			{
				// 弹出一个对话框，告诉用户程序结束
				MessageBox(NULL,TEXT("程序将被关闭"),TEXT("错误"),MB_OK|MB_ICONSTOP);
				return FALSE;               // 退出并返回 FALSE
			}
		}
	}
	if (fullscreen)	// 仍处于全屏模式吗?
	{
		dwExStyle=WS_EX_APPWINDOW;	// 扩展窗体风格
		dwStyle=WS_POPUP;			// 窗体风格
		ShowCursor(FALSE);          // 隐藏鼠标指针
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	// 扩展窗体风格
		dwStyle=WS_OVERLAPPEDWINDOW;                    // 窗体风格
	}
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle); // 调整窗口大小
	if (!(hWnd=CreateWindowEx(        
		dwExStyle,									// 扩展窗体风格
		TEXT("OpenGL"),								// 类名字
		getWCHAR(title),							// 窗口标题
		WS_CLIPSIBLINGS |							// 必须的窗体风格属性
		WS_CLIPCHILDREN |							// 必须的窗体风格属性
		dwStyle,									// 选择的窗体属性
		0, 0,										// 窗口位置
		WindowRect.right-WindowRect.left,			// 宽度
		WindowRect.bottom-WindowRect.top,			// 高度
		NULL,                                       // 无父窗口
		NULL,                                       // 无菜单
		hInstance,                                  // 实例
		NULL)))										// 不向WM_CREATE传递任何东东
	{
		KillGLWindow();	// 重置显示区
		MessageBox(NULL,TEXT("不能创建一个窗口设备描述表"),TEXT("错误"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// 返回 FALSE
	}
	static PIXELFORMATDESCRIPTOR pfd=	// /pfd 告诉窗使用的像素格式
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// 上述格式描述符的大小
		1,											// 版本号
		PFD_DRAW_TO_WINDOW |                        // 格式支持窗口
		PFD_SUPPORT_OPENGL |						// 格式必须支持OpenGL
		PFD_DOUBLEBUFFER,							// 必须支持双缓冲
		PFD_TYPE_RGBA,								// 申请 RGBA 格式
		bits,                                       // 选定色彩深度
		0, 0, 0, 0, 0, 0,                           // 忽略的色彩位
		0,                                          // 无Alpha缓存
		0,                                          // 忽略Shift Bit
		0,                                          // 无累加缓存
		0, 0, 0, 0,                                 // 忽略聚集位
		16,                                         // 16位 Z-缓存 (深度缓存)
		0,                                          // 无蒙板缓存
		0,                                          // 无辅助缓存
		PFD_MAIN_PLANE,								// 主绘图层
		0,                                          // Reserved
		0, 0, 0                                     // 忽略层遮罩
	};
	if (!(hDC=GetDC(hWnd)))	// 取得设备描述表了么?
	{
		KillGLWindow();	// 重置显示区
		MessageBox(NULL,TEXT("不能创建一种相匹配的像素格式"),TEXT("错误"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// 返回 FALSE
	}
	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Windows 找到相应的象素格式了吗?
	{
		KillGLWindow();	// 重置显示区
		MessageBox(NULL,TEXT("不能设置像素格式"),TEXT("错误"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// 返回 FALSE
	}
	if(!SetPixelFormat(hDC,PixelFormat,&pfd))	// 能够设置象素格式么?
	{
		KillGLWindow();	// 重置显示区
		MessageBox(NULL,TEXT("不能设置像素格式"),TEXT("错误"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// 返回 FALSE
	}
	if (!(hRC=wglCreateContext(hDC)))	// 能否取得着色描述表?
	{
		KillGLWindow();	// 重置显示区
		MessageBox(NULL,TEXT("不能创建OpenGL渲染描述表"),TEXT("错误"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// 返回 FALSE
	}
	if(!wglMakeCurrent(hDC,hRC))	// 尝试激活着色描述表
	{
		KillGLWindow();	// 重置显示区
		MessageBox(NULL,TEXT("不能激活当前的OpenGL渲然描述表"),TEXT("错误"),MB_OK|MB_ICONEXCLAMATION);
		return FALSE;	// 返回 FALSE
	}
	ShowWindow(hWnd,SW_SHOW);	// 显示窗口
	SetForegroundWindow(hWnd);	// 略略提高优先级
	SetFocus(hWnd);	// 设置键盘的焦点至此窗口

	return TRUE;	// 成功
}



LRESULT CALLBACK WndProc( 
	HWND hWnd,                          // 窗口的句柄
	UINT uMsg,                          // 窗口的消息
	WPARAM wParam,                      // 附加的消息内容
	LPARAM lParam)						// 附加的消息内容
{
	switch (uMsg)	// 检查Windows消息
	{
	case WM_ACTIVATE:	// 监视窗口激活消息
		{
			if (!HIWORD(wParam))	// 检查最小化状态
			{
				active=TRUE;	// 程序处于激活状态
			}
			else
			{
				active=FALSE;	// 程序不再激活
			}

			return 0;			// 返回消息循环
		}
	case WM_SYSCOMMAND:				// 系统中断命令
		{
			switch (wParam)		// 检查系统调用
			{
			case SC_SCREENSAVE:		// 屏保要运行?
			case SC_MONITORPOWER:	// 显示器要进入节电模式?
				return 0;      // 阻止发生
			}
			break;	// 退出
		}
	case WM_CLOSE:	// 收到Close消息?
		{
			PostQuitMessage(0);	// 发出退出消息
			return 0;	// 返回
		}
	case WM_KEYDOWN:	// 有键按下么?
		{
			keys[wParam] = TRUE;	// 如果是，设为TRUE
			return 0;	// 返回
		}
	case WM_KEYUP:	// 有键放开么?
		{
			keys[wParam] = FALSE;	// 如果是，设为FALSE
			return 0;	// 返回
		}
	case WM_SIZE:		// 调整OpenGL窗口大小
		{
			wndRender->setFrameSize(LOWORD(lParam),HIWORD(lParam));                      // LoWord=Width,HiWord=Height
			return 0;	// 返回
		}
// 	case WM_MOUSEMOVE:
// 	{
// 
// 	}
// 	case WM_LBUTTONDOWN:
// 	case WM_LBUTTONUP:
	}
	// 向 DefWindowProc传递所有未处理的默认消息。
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}



int  WINAPI WinMain(HINSTANCE	hInstance,                 // 当前窗口实例
					HINSTANCE	hPrevInstance,             // 前一个窗口实例
					LPSTR		lpCmdLine,                 // 命令行参数
					int			nCmdShow)                  // 窗口显示状态
{

	//控制台输出
	AllocConsole();
	//AttachConsole(ATTACH_PARENT_PROCESS); // 将当前程序附着到父进程上  
	freopen("CONIN$", "r+t", stdin); // 重定向 STDIN  
	freopen("CONOUT$", "w+t", stdout); // 重定向STDOUT  

	MSG msg;			// Windowsx消息结构
	BOOL done=FALSE;	// 用来退出循环的Bool 变量
	// 提示用户选择运行模式
// 	if (MessageBox(NULL,TEXT("你想在全屏模式下运行么？"), TEXT("设置全屏模式"),MB_YESNO|MB_ICONQUESTION)==IDNO)
// 	{
// 		fullscreen=FALSE; // FALSE为窗口模式
// 	}

	fullscreen = FALSE; // FALSE为窗口模式
	// 创建OpenGL窗口
	// CreateGLWindow函数的参数依次为标题、宽度、高度、色彩深度，以及全屏标志。就这么简单！我很欣赏这段代码的简洁。如果未能创建成功，函数返回FALSE。程序立即退出
	if (!CreateGLWindow("win32 ",WINDOW_SIZE_WIDTH,WINDOW_SIZE_HEIGHT,16,fullscreen))
	{
		return 0;	// 失败退出
	}

	wndRender = new WndRender();
	wndRender->setFrameSize(WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);
	wndRender->test();
	
	//wndWeb = new WndWeb(WEB_IP, WEB_PORT);

	while(!done)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			if (msg.message==WM_QUIT)
			{
				done=TRUE;
			}
			else
			{
				TranslateMessage(&msg);                                  // 翻译消息
				DispatchMessage(&msg);                                   // 发送消息
			}
		}
		else // 如果没有消息
		{
			if (active)
			{
				if (keys[VK_ESCAPE])
				{
					done=TRUE;
				}
				else
				{
					wndRender->update();		// 绘制场景
					SwapBuffers(hDC);			// 交换缓存 (双缓存)
					
				}
			}
			//wndWeb->update();
		}
	}
	// 关闭程序
	KillGLWindow();                                                                                                                                                          // 销毁窗口
	return (msg.wParam);                                                                                                                           // 退出程序
}

*/