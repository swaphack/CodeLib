#include "GLFrame.h"

using namespace render;

using namespace sys;

DeviceProxy::DeviceProxy(const TouchManager* touchManager)
{
	ASSERT(touchManager != nullptr);
	_touchManager = (TouchManager*)touchManager;

	_keyboardManager = G_KEYBOARDMANAGER;
}

DeviceProxy::~DeviceProxy()
{

}

void DeviceProxy::onMouseButtonHandler(MouseKey key, ButtonStatus type, float x, float y)
{
	if (key != EMK_LEFTBUTTON)
	{
		return;
	}

	if (_touchManager == nullptr)
	{
		return;
	}

	sys::Volume size = Tool::getGLViewSize();
	if (type == EBS_BUTTON_DOWN)
	{
		_touchManager->onTouchBegan(x, size.height - y);
	}
	else if (type == EBS_BUTTON_UP)
	{
		_touchManager->onTouchEnd(x, size.height - y);
	}
}

void DeviceProxy::onMouseMoveHandler(float x, float y)
{
	if (_touchManager == nullptr)
	{
		return;
	}

	sys::Volume size = Tool::getGLViewSize();
	_touchManager->onTouchMove(x, size.height - y);
}

void DeviceProxy::onKeyBoardButtonHandler(sys::BoardKey key, sys::ButtonStatus type)
{
	_keyboardManager->onDispatcher(key, type);
}


//////////////////////////////////////////////////////////////////////////
GLFrame::GLFrame()
:_glrc(NULL),
_dc(NULL),
_bits(0),
_render(nullptr),
_deviceProxy(nullptr)
{
	_keyboard = new sys::Keyboard();
	_mouse = new sys::Mouse();
}

GLFrame::~GLFrame()
{
	SAFE_DELETE(_deviceProxy);
	SAFE_DELETE(_render);
}

void GLFrame::initWindow(const char* title, int width, int height, int bits, RenderApplication* render)
{
	ASSERT(render != nullptr);

	ASSERT(_render == nullptr);

	_bits = bits;
	_render = render;

	Window::initWindow(title, width, height);
}

bool GLFrame::init()
{
	if (!Window::init())
	{
		return false;
	}

	uint PixelFormat = 0;
	static PIXELFORMATDESCRIPTOR pfd =	// /pfd 告诉窗使用的像素格式
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// 上述格式描述符的大小
		1,											// 版本号
		PFD_DRAW_TO_WINDOW |                        // 格式支持窗口
		PFD_SUPPORT_OPENGL |						// 格式必须支持OpenGL
		PFD_DOUBLEBUFFER,							// 必须支持双缓冲
		PFD_TYPE_RGBA,								// 申请 RGBA 格式
		_bits,                                      // 选定色彩深度
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
	if (!(_dc = GetDC(_wnd)))	// 取得设备描述表了么?
	{
		dispose();	// 重置显示区
		MessageBox(NULL, TEXT("不能创建一种相匹配的像素格式"), TEXT("错误"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// 返回 FALSE
	}
	if (!(PixelFormat = ChoosePixelFormat(_dc, &pfd)))	// Windows 找到相应的象素格式了吗?
	{
		dispose();	// 重置显示区
		MessageBox(NULL, TEXT("不能设置像素格式"), TEXT("错误"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// 返回 FALSE
	}
	if (!SetPixelFormat(_dc, PixelFormat, &pfd))	// 能够设置象素格式么?
	{
		dispose();	// 重置显示区
		MessageBox(NULL, TEXT("不能设置像素格式"), TEXT("错误"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// 返回 FALSE
	}
	if (!(_glrc = wglCreateContext(_dc)))	// 能否取得着色描述表?
	{
		dispose();	// 重置显示区
		MessageBox(NULL, TEXT("不能创建OpenGL渲染描述表"), TEXT("错误"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// 返回 FALSE
	}
	if (!wglMakeCurrent(_dc, _glrc))	// 尝试激活着色描述表
	{
		dispose();	// 重置显示区
		MessageBox(NULL, TEXT("不能激活当前的OpenGL渲然描述表"), TEXT("错误"), MB_OK | MB_ICONEXCLAMATION);
		return false;	// 返回 FALSE
	}
	ShowWindow(_wnd, SW_SHOW);	// 显示窗口
	SetForegroundWindow(_wnd);	// 略略提高优先级
	SetFocus(_wnd);	// 设置键盘的焦点至此窗口

	return true;
}

bool GLFrame::dispose()
{
	if (_dc)	// 我们拥有OpenGL渲染描述表吗?
	{
		if (!wglMakeCurrent(NULL, NULL))	// 我们能否释放DC和RC描述表?
		{
			MessageBox(NULL, TEXT("释放DC或RC失败。"), TEXT("关闭错误"), MB_OK | MB_ICONINFORMATION);
		}
		if (!wglDeleteContext(_glrc))	// 我们能否删除RC?
		{
			MessageBox(NULL, TEXT("释放RC失败。"), TEXT("关闭错误"), MB_OK | MB_ICONINFORMATION);
		}
		_glrc = NULL;	// 将RC设为 NULL
	}
	if (_dc && !ReleaseDC(_wnd, _dc))	// 我们能否释放 DC?
	{
		MessageBox(NULL, TEXT("释放DC失败。"), TEXT("关闭错误"), MB_OK | MB_ICONINFORMATION);
		_dc = NULL;	// 将 DC 设为 NULL
	}

	return Window::dispose();
}

void GLFrame::listen()
{
	MSG msg;
	bool done = false;

	if (_render)
	{
		_render->setFrameSize(getWidth(), getHeight());
		_render->show();
		this->initDevice();
	}

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
		else // 如果没有消息
		{
			if (_render)
			{
				_render->update();		// 绘制场景
				SwapBuffers(_dc);			// 交换缓存 (双缓存)
			}
		}
	}
	// 关闭程序
	dispose();
}

bool GLFrame::onHandSignal(sys::Signal* signal)
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

void GLFrame::initDevice()
{
	if (_render == nullptr)
	{
		return;
	}
	if (_deviceProxy == nullptr)
	{
		_deviceProxy = new DeviceProxy(_render->getCanvas()->getTouchManager());
	}
	if (getMouse())
	{
		getMouse()->setButtonHandler(_deviceProxy, MOUSE_BUTTON_SELECTOR(DeviceProxy::onMouseButtonHandler));
		getMouse()->setMoveHandler(_deviceProxy, MOUSE_MOVE_SELECTOR(DeviceProxy::onMouseMoveHandler));
	}

	if (getKeyboard())
	{
		getKeyboard()->setKeyhandler(_deviceProxy, KEYBOARD_BUTTON_SELECTOR(DeviceProxy::onKeyBoardButtonHandler));
	}
}
