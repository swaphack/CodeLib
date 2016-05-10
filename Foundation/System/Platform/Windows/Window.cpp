#include "Window.h"

using namespace sys;


static Window* g_Window = nullptr;

LRESULT CALLBACK WndProc(
	HWND hWnd,                          // ���ڵľ��
	UINT uMsg,                          // ���ڵ���Ϣ
	WPARAM wParam,                      // ���ӵ���Ϣ����
	LPARAM lParam)						// ���ӵ���Ϣ����
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
	// �� DefWindowProc��������δ�����Ĭ����Ϣ��
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
	//����Ҫ��WindowsΪ����Ѱ����ƥ������ظ�ʽʱ��WindowsѰ�ҽ�����ģʽֵ�����ڱ���PixelFormat��
	WNDCLASS sys;				// ������ṹ
	DWORD dwExStyle;			// ��չ���ڷ��
	DWORD dwStyle;				// ���ڷ��
	RECT WindowRect;			// ȡ�þ��ε����ϽǺ����½ǵ�����ֵ

	long left = (GetSystemMetrics(SM_CXSCREEN) - _width)* 0.5f;
	long top = (GetSystemMetrics(SM_CYSCREEN) - _height)* 0.5f;


	WindowRect.left = (long)left;			// ��Left   ��Ϊ 0
	WindowRect.right = (long)left + _width;       // ��Right ��ΪҪ��Ŀ��
	WindowRect.top = (long)top;             // ��Top    ��Ϊ 0
	WindowRect.bottom = (long)top + _height;     // ��Bottom ��ΪҪ��ĸ߶�

	_instance = GetModuleHandle(NULL);          // ȡ�����Ǵ��ڵ�ʵ��

	sys.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// �ƶ�ʱ�ػ�����Ϊ����ȡ��DC��CS_OWNDCΪ���ڴ���һ��˽�е�DC������ζ��DC�����ڳ���乲��
	sys.lpfnWndProc = (WNDPROC)WndProc;             // WndProc������Ϣ
	sys.cbClsExtra = 0;                              // �޶��ⴰ������
	sys.cbWndExtra = 0;                              // �޶��ⴰ������
	sys.hInstance = _instance;						// ����ʵ��
	sys.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// װ��ȱʡͼ��
	sys.hCursor = LoadCursor(NULL, IDC_ARROW);		// װ��Ĭ�����ָ��
	sys.hbrBackground = NULL;                        // GL����Ҫ����
	sys.lpszMenuName = NULL;                        // ����Ҫ�˵�
	sys.lpszClassName = TEXT("OpenGL");              // �趨������

	if (!RegisterClass(&sys))	// ����ע�ᴰ����
	{
		MessageBox(NULL, TEXT("ע�ᴰ��ʧ��"), TEXT("����"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// �˳�������FALSE
	}

	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;	// ��չ������
	dwStyle = WS_OVERLAPPEDWINDOW;                    // ������

	//AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle); // �������ڴ�С
	if (!(_wnd = CreateWindowEx(
		dwExStyle,									// ��չ������
		TEXT("OpenGL"),								// ������
		TEXT(_title.c_str()),							// ���ڱ���
		WS_CLIPSIBLINGS |							// ����Ĵ���������
		WS_CLIPCHILDREN |							// ����Ĵ���������
		dwStyle,									// ѡ��Ĵ�������
		WindowRect.left, WindowRect.top,			// ����λ��
		WindowRect.right - WindowRect.left,			// ���
		WindowRect.bottom - WindowRect.top,			// �߶�
		NULL,                                       // �޸�����
		NULL,                                       // �޲˵�
		_instance,                                  // ʵ��
		NULL)))										// ����WM_CREATE�����κζ���
	{
		dispose();	// ������ʾ��
		MessageBox(NULL, TEXT("���ܴ���һ�������豸������"), TEXT("����"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// ���� FALSE
	}

	return true;
}

bool Window::dispose()
{
	if (_wnd && !DestroyWindow(_wnd))	// �ܷ����ٴ���?
	{
		MessageBox(NULL, TEXT("�ͷŴ��ھ��ʧ�ܡ�"), TEXT("�رմ���"), MB_OK | MB_ICONINFORMATION);
		_wnd = NULL;	// �� hWnd ��Ϊ NULL
	}
	if (!UnregisterClass(TEXT("OpenGL"), _instance))	// �ܷ�ע����?
	{
		MessageBox(NULL, TEXT("����ע�������ࡣ"), TEXT("�رմ���"), MB_OK | MB_ICONINFORMATION);
		_instance = NULL;	// �� hInstance ��Ϊ NULL
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
				TranslateMessage(&msg);                                  // ������Ϣ
				DispatchMessage(&msg);                                   // ������Ϣ
			}
		}
	}
	// �رճ���
	dispose();
}




