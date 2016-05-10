#include "Window.h"

using namespace sys;


static Window* g_Window = nullptr;

LRESULT CALLBACK WndProc(
	HWND hWnd,                          // 窗口的句柄
	UINT uMsg,                          // 窗口的消息
	WPARAM wParam,                      // 附加的消息内容
	LPARAM lParam)						// 附加的消息内容
{
	if (g_Window)
	{
		Tuple3<UINT, WPARAM, LPARAM>* params = new Tuple3<UINT, WPARAM, LPARAM>(uMsg, wParam, lParam);
		Signal* signal = new Signal();
		signal->setMessage(params);
		if (g_Window->onRecvSignal(signal))
		{
			delete params;
			delete signal;
			return 0;
		}
		delete params;
		delete signal;

	}
	// 向 DefWindowProc传递所有未处理的默认消息。
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


LPCWCHAR getWCHAR(const char* szStr)
{
	WCHAR wszClassName[256];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, wszClassName,
		sizeof(wszClassName) / sizeof(wszClassName[0]));

	return wszClassName;
}

//////////////////////////////////////////////////////////////////////////

Window::Window()
:_wnd(NULL),
_instance(NULL),
_width(0),
_height(0),
_posX(-1),
_posY(-1)
{
	ASSERT(g_Window == nullptr);
	g_Window = this;
}

Window::~Window()
{
	this->dispose();
	g_Window = nullptr;
}

void Window::initWindow(const char* title, int width, int height)
{
	_title = title;
	_width = width;
	_height = height;

	if (!this->init())
	{
		return;
	}
	
	this->listen();
}

bool Window::onRecvSignal(Signal* signal)
{
	if (signal == nullptr)
	{
		return false;
	}

	Tuple3<UINT, WPARAM, LPARAM>* params = static_cast<Tuple3<UINT, WPARAM, LPARAM>*>(signal->getMessage());
	if (params == nullptr)
	{
		return false;
	}

	switch (params->t1)
	{
	default:
		return false;
	}

	return true;
}

bool Window::init()
{
	//我们要求Windows为我们寻找相匹配的象素格式时，Windows寻找结束后将模式值保存在变量PixelFormat中
	WNDCLASS sys;				// 窗口类结构
	DWORD dwExStyle;			// 扩展窗口风格
	DWORD dwStyle;				// 窗口风格
	RECT WindowRect;			// 取得矩形的左上角和右下角的坐标值

	long left = (GetSystemMetrics(SM_CXSCREEN) - _width)* 0.5f;
	long top = (GetSystemMetrics(SM_CYSCREEN) - _height)* 0.5f;


	WindowRect.left = (long)left;			// 将Left   设为 0
	WindowRect.right = (long)left + _width;       // 将Right 设为要求的宽度
	WindowRect.top = (long)top;             // 将Top    设为 0
	WindowRect.bottom = (long)top + _height;     // 将Bottom 设为要求的高度

	_instance = GetModuleHandle(NULL);          // 取得我们窗口的实例

	sys.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// 移动时重画，并为窗口取得DC，CS_OWNDC为窗口创建一个私有的DC。这意味着DC不能在程序间共享。
	sys.lpfnWndProc = (WNDPROC)WndProc;             // WndProc处理消息
	sys.cbClsExtra = 0;                              // 无额外窗口数据
	sys.cbWndExtra = 0;                              // 无额外窗口数据
	sys.hInstance = _instance;						// 设置实例
	sys.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// 装入缺省图标
	sys.hCursor = LoadCursor(NULL, IDC_ARROW);		// 装入默认鼠标指针
	sys.hbrBackground = NULL;                        // GL不需要背景
	sys.lpszMenuName = NULL;                        // 不需要菜单
	sys.lpszClassName = TEXT("OpenGL");              // 设定类名字

	if (!RegisterClass(&sys))	// 尝试注册窗口类
	{
		MessageBox(NULL, TEXT("注册窗口失败"), TEXT("错误"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// 退出并返回FALSE
	}

	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	// 扩展窗体风格
	dwStyle = WS_OVERLAPPEDWINDOW;                    // 窗体风格

	//AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle); // 调整窗口大小
	if (!(_wnd = CreateWindowEx(
		dwExStyle,									// 扩展窗体风格
		TEXT("OpenGL"),								// 类名字
		TEXT(_title.c_str()),							// 窗口标题
		WS_CLIPSIBLINGS |							// 必须的窗体风格属性
		WS_CLIPCHILDREN |							// 必须的窗体风格属性
		dwStyle,									// 选择的窗体属性
		WindowRect.left, WindowRect.top,			// 窗口位置
		WindowRect.right - WindowRect.left,			// 宽度
		WindowRect.bottom - WindowRect.top,			// 高度
		NULL,                                       // 无父窗口
		NULL,                                       // 无菜单
		_instance,                                  // 实例
		NULL)))										// 不向WM_CREATE传递任何东东
	{
		dispose();	// 重置显示区
		MessageBox(NULL, TEXT("不能创建一个窗口设备描述表"), TEXT("错误"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// 返回 FALSE
	}

	return true;
}

bool Window::dispose()
{
	if (_wnd && !DestroyWindow(_wnd))	// 能否销毁窗口?
	{
		MessageBox(NULL, TEXT("释放窗口句柄失败。"), TEXT("关闭错误"), MB_OK | MB_ICONINFORMATION);
		_wnd = NULL;	// 将 hWnd 设为 NULL
	}
	if (!UnregisterClass(TEXT("OpenGL"), _instance))	// 能否注销类?
	{
		MessageBox(NULL, TEXT("不能注销窗口类。"), TEXT("关闭错误"), MB_OK | MB_ICONINFORMATION);
		_instance = NULL;	// 将 hInstance 设为 NULL
	}

	return true;
}

void Window::listen()
{
	MSG msg;
	bool done = false;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				done = TRUE;
			}
			else
			{
				TranslateMessage(&msg);                                  // 翻译消息
				DispatchMessage(&msg);                                   // 发送消息
			}
		}
	}
	// 关闭程序
	dispose();
}




