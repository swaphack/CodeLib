#include "GLWindow.h"
#include "Platform/DeviceProxy.h"
#include "RenderApplication.h"
#include "Graphic/GLAPI/GLVersion.h"
#include "Common/Input/KeyChar.h"

using namespace render;

using namespace sys;

GLWindow::GLWindow()
:_glrc(NULL),
_dc(NULL),
_bits(0),
_render(nullptr),
_deviceProxy(nullptr)
{
	_deviceProxy = new DeviceProxy();
}

GLWindow::~GLWindow()
{
	SAFE_DELETE(_deviceProxy);
	SAFE_DELETE(_render);

	SAFE_DELETE(_keyboard);
	SAFE_DELETE(_mouse);
}

void GLWindow::createWindow(const std::string& title, int width, int height, int millis, RenderApplication* render)
{
	ASSERT(render != nullptr);

	ASSERT(_render == nullptr);

	_bits = 32;
	_render = render;
	_render->setRefreshInterval(millis / 1000.0f);

	Window::initWindow(title, width, height);

	int err = glewInit();
	if (GLEW_OK != err)
	{
		PRINT("Error [main]: glewInit failed: %s\n", glewGetErrorString(err));
		return;
	}

	GLVersion::showDetail();

	if (_render)
	{
		_render->setFrameSize((int)getWidth(), (int)getHeight());
		_render->show();
	}

	this->initDevice();
	this->listen();
}

bool GLWindow::init()
{
	if (!Window::init())
	{
		return false;
	}

	uint32_t PixelFormat = 0;
	static PIXELFORMATDESCRIPTOR pfd =	// /pfd ���ߴ�ʹ�õ����ظ�ʽ
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// ������ʽ�������Ĵ�С
		1,											// �汾��
		PFD_DRAW_TO_WINDOW |                        // ��ʽ֧�ִ���
		PFD_SUPPORT_OPENGL |						// ��ʽ����֧��OpenGL
		PFD_DOUBLEBUFFER,							// ����֧��˫����
		PFD_TYPE_RGBA,								// ���� RGBA ��ʽ
		_bits,                                      // ѡ��ɫ�����
		0, 0, 0, 0, 0, 0,                           // ���Ե�ɫ��λ
		1,                                          // Alpha����
		0,                                          // ����Shift Bit
		1,                                          // �ۼӻ���
		0, 0, 0, 0,                                 // ���Ծۼ�λ
		32,                                         // 32λ Z-���� (��Ȼ���)
		1,                                          // ����ģ�建��
		0,                                          // �޸�������
		PFD_MAIN_PLANE,								// ����ͼ��
		0,                                          // Reserved
		0, 0, 0                                     // ���Բ�����
	};
	if (!(_dc = GetDC(_wnd)))	// ȡ���豸��������ô?
	{
		dispose();	// ������ʾ��
		MessageBox(NULL, TEXT("���ܴ���һ����ƥ������ظ�ʽ"), TEXT("����"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// ���� FALSE
	}
	if (!(PixelFormat = ChoosePixelFormat(_dc, &pfd)))	// Windows �ҵ���Ӧ�����ظ�ʽ����?
	{
		dispose();	// ������ʾ��
		MessageBox(NULL, TEXT("�����������ظ�ʽ"), TEXT("����"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// ���� FALSE
	}
	if (!SetPixelFormat(_dc, PixelFormat, &pfd))	// �ܹ��������ظ�ʽô?
	{
		dispose();	// ������ʾ��
		MessageBox(NULL, TEXT("�����������ظ�ʽ"), TEXT("����"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// ���� FALSE
	}
	if (!(_glrc = wglCreateContext(_dc)))	// �ܷ�ȡ����ɫ������?
	{
		dispose();	// ������ʾ��
		MessageBox(NULL, TEXT("���ܴ���OpenGL��Ⱦ������"), TEXT("����"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// ���� FALSE
	}
	if (!wglMakeCurrent(_dc, _glrc))	// ���Լ�����ɫ������
	{
		dispose();	// ������ʾ��
		MessageBox(NULL, TEXT("���ܼ��ǰ��OpenGL��Ȼ������"), TEXT("����"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// ���� FALSE
	}
	ShowWindow(_wnd, SW_SHOW);	// ��ʾ����
	SetForegroundWindow(_wnd);	// ����������ȼ�
	SetFocus(_wnd);	// ���ü��̵Ľ������˴���

	return true;
}

bool GLWindow::dispose()
{
	if (_dc)	// ����ӵ��OpenGL��Ⱦ��������?
	{
		if (!wglMakeCurrent(NULL, NULL))	// �����ܷ��ͷ�DC��RC������?
		{
			MessageBox(NULL, TEXT("�ͷ�DC��RCʧ�ܡ�"), TEXT("�رմ���"), MB_OK | MB_ICONINFORMATION);
		}
		if (!wglDeleteContext(_glrc))	// �����ܷ�ɾ��RC?
		{
			MessageBox(NULL, TEXT("�ͷ�RCʧ�ܡ�"), TEXT("�رմ���"), MB_OK | MB_ICONINFORMATION);
		}
		_glrc = NULL;	// ��RC��Ϊ NULL
	}
	if (_dc && !ReleaseDC(_wnd, _dc))	// �����ܷ��ͷ� DC?
	{
		MessageBox(NULL, TEXT("�ͷ�DCʧ�ܡ�"), TEXT("�رմ���"), MB_OK | MB_ICONINFORMATION);
		_dc = NULL;	// �� DC ��Ϊ NULL
	}

	return Window::dispose();
}

void GLWindow::listen()
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
		else // ���û����Ϣ
		{
			if (_render)
			{
				_render->update();		// ���Ƴ���
				SwapBuffers(_dc);			// �������� (˫����)
			}
		}
	}
	// �رճ���
	dispose();
}

bool GLWindow::onHandSignal(sys::Signal* signal)
{
	if (signal == nullptr)
	{
		return false;
	}

	if (Window::onHandSignal(signal))
	{
		return true;
	}

	sys::Tuple3<UINT, WPARAM, LPARAM>* params = static_cast<sys::Tuple3<UINT, WPARAM, LPARAM>*>(signal->getMessage());
	if (params == nullptr)
	{
		return false;
	}

	switch (params->t1)
	{
	case WM_SIZE:
	{
		if (_render)
		{
			_render->setFrameSize(LOWORD(params->t3), HIWORD(params->t3));
		}
		break;
	}
	default:
		return false;
		break;
	}

	return true;
}

void GLWindow::initDevice()
{
	if (_render == nullptr)
	{
		return;
	}
	if (getMouse())
	{
		getMouse()->setButtonHandler(_deviceProxy, MOUSE_BUTTON_SELECTOR(DeviceProxy::onMouseButtonHandler));
		getMouse()->setMoveHandler(_deviceProxy, MOUSE_MOVE_SELECTOR(DeviceProxy::onMouseMoveHandler));
		getMouse()->setScrollHandler(_deviceProxy, MOUSE_SCROLL_SELECTOR(DeviceProxy::onMouseScrollHandler));
	}

	if (getKeyboard())
	{
		getKeyboard()->setKeyhandler(_deviceProxy, KEYBOARD_BUTTON_SELECTOR(DeviceProxy::onKeyBoardButtonHandler));

		// ��Сд��
		if (GetKeyState(VK_CAPITAL) & 1)
		{
			getKeyboard()->onKeyEvent(sys::BoardKey::KCAPITAL, sys::ButtonStatus::BUTTON_DOWN);
		}
		// ������
		if (GetKeyState(VK_NUMLOCK) & 1)
		{
			getKeyboard()->onKeyEvent(sys::BoardKey::KNUMLOCK, sys::ButtonStatus::BUTTON_DOWN);
		}
	}
}
