#include "Window.h"

using namespace sys;

#include <map>

class Windows
{
public:
	Windows();
	~Windows();
public:
	void addWindow(HWND wnd, Window* window);
	void removeWindow(HWND wnd);
	Window* getWindow(HWND hwnd);
private:
	std::map<HWND, Window*> _windows;
};

Windows::Windows()
{

}

Windows::~Windows()
{
	_windows.clear();
}

void Windows::addWindow(HWND wnd, Window* window)
{
	if (window == nullptr)
	{
		return;
	}
	_windows[wnd] = window;
}

void Windows::removeWindow(HWND wnd)
{
	_windows.erase(wnd);
}

Window* Windows::getWindow(HWND hwnd)
{
	std::map<HWND, Window*>::iterator it = _windows.find(hwnd);
	if (it != _windows.end())
	{
		return it->second;
	}

	return nullptr;
}


//////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(
	HWND hWnd,                          // ���ڵľ��
	UINT uMsg,                          // ���ڵ���Ϣ
	WPARAM wParam,                      // ���ӵ���Ϣ����
	LPARAM lParam)						// ���ӵ���Ϣ����
{
	Window* window = Instance<Windows>::getInstance()->getWindow(hWnd);
	if (window)
	{
		Tuple3<UINT, WPARAM, LPARAM>* params = new Tuple3<UINT, WPARAM, LPARAM>(uMsg, wParam, lParam);
		Signal* signal = new Signal();
		signal->setMessage(params);
		if (window->onRecvSignal(signal))
		{
			delete params;
			delete signal;
			return 0;
		}
		delete params;
		delete signal;

	}
	// �� DefWindowProc��������δ������Ĭ����Ϣ��
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

#define CLASS_NAME "OpenGL"

Window::Window()
:_wnd(NULL),
_instance(NULL),
_width(0),
_height(0),
_posX(-1),
_posY(-1),
_keyBoard(nullptr),
_mouse(nullptr)
{
}

Window::~Window()
{
	this->dispose();

	Instance<Windows>::getInstance()->removeWindow(getWnd());
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

	if (onHandSignal(signal))
	{
		return true;
	}

	return false;
}

KeyBoard* Window::getKeyBoard()
{
	return _keyBoard;
}

Mouse* Window::getMouse()
{
	return _mouse;
}

bool Window::init()
{
	//����Ҫ��WindowsΪ����Ѱ����ƥ������ظ�ʽʱ��WindowsѰ�ҽ�����ģʽֵ�����ڱ���PixelFormat��
	WNDCLASS sys;				// ������ṹ
	DWORD dwExStyle;			// ��չ���ڷ��
	DWORD dwStyle;				// ���ڷ��

	long left = (GetSystemMetrics(SM_CXSCREEN) - _width)* 0.5f;
	long top = (GetSystemMetrics(SM_CYSCREEN) - _height)* 0.5f;

	_instance = GetModuleHandle(NULL);          // ȡ�����Ǵ��ڵ�ʵ��

	sys.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// �ƶ�ʱ�ػ�����Ϊ����ȡ��DC��CS_OWNDCΪ���ڴ���һ��˽�е�DC������ζ��DC�����ڳ���乲����
	sys.lpfnWndProc = (WNDPROC)WndProc;             // WndProc������Ϣ
	sys.cbClsExtra = 0;                              // �޶��ⴰ������
	sys.cbWndExtra = 0;                              // �޶��ⴰ������
	sys.hInstance = _instance;						// ����ʵ��
	sys.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// װ��ȱʡͼ��
	sys.hCursor = LoadCursor(NULL, IDC_ARROW);		// װ��Ĭ�����ָ��
	sys.hbrBackground = NULL;                        // GL����Ҫ����
	sys.lpszMenuName = NULL;                        // ����Ҫ�˵�
	sys.lpszClassName = TEXT(CLASS_NAME);              // �趨������

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
		TEXT(CLASS_NAME),								// ������
		TEXT(_title.c_str()),							// ���ڱ���
		WS_CLIPSIBLINGS |							// ����Ĵ���������
		WS_CLIPCHILDREN |							// ����Ĵ���������
		dwStyle,									// ѡ��Ĵ�������
		left, top,									// ����λ��
		_width,										// ����
		_height,									// �߶�
		NULL,                                       // �޸�����
		NULL,                                       // �޲˵�
		_instance,                                  // ʵ��
		NULL)))										// ����WM_CREATE�����κζ���
	{
		dispose();	// ������ʾ��
		MessageBox(NULL, TEXT("���ܴ���һ�������豸������"), TEXT("����"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// ���� FALSE
	}

	Instance<Windows>::getInstance()->addWindow(this->getWnd(), this);

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

bool Window::onHandSignal(Signal* signal)
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
	case WM_ACTIVATE:
	{
		if (!HIWORD(params->t2))
		{
		}
		break;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	case WM_KEYDOWN:
	{
		if (getKeyBoard())
		{
			getKeyBoard()->onKeyEvent((BoardKey)params->t2, EBS_BUTTON_DOWN);
		}
		break;
	}
	case WM_KEYUP:
	{
		if (getKeyBoard())
		{
			getKeyBoard()->onKeyEvent((BoardKey)params->t2, EBS_BUTTON_UP);
		}
		break;
	}
	case WM_LBUTTONDOWN:
	{
		if (getMouse())
		{
			getMouse()->onButtonHandler(EMK_LEFTBUTTON, EBS_BUTTON_DOWN, LOWORD(params->t3), HIWORD(params->t3));
		}
		break;
	}
	case WM_LBUTTONUP:
	{
		if (getMouse())
		{
			getMouse()->onButtonHandler(EMK_LEFTBUTTON, EBS_BUTTON_UP, LOWORD(params->t3), HIWORD(params->t3));
		}
		break;
	}
	case WM_RBUTTONDOWN:
	{
		if (getMouse())
		{
			getMouse()->onButtonHandler(EMK_RIGHTBUTTON, EBS_BUTTON_DOWN, LOWORD(params->t3), HIWORD(params->t3));
		}
		break;
	}
	case WM_RBUTTONUP:
	{
		if (getMouse())
		{
			getMouse()->onButtonHandler(EMK_RIGHTBUTTON, EBS_BUTTON_UP, LOWORD(params->t3), HIWORD(params->t3));
		}
		break;
	}
	case WM_MOUSEMOVE:
		if (getMouse())
		{
			getMouse()->onMoveHandler(LOWORD(params->t3), HIWORD(params->t3));
		}
		break;
	default:
		return false;
		break;
	}

	return true;
}



