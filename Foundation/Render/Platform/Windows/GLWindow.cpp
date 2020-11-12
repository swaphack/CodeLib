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
		1,                                          // Alpha缓存
		0,                                          // 忽略Shift Bit
		1,                                          // 累加缓存
		0, 0, 0, 0,                                 // 忽略聚集位
		32,                                         // 32位 Z-缓存 (深度缓存)
		1,                                          // 开启模板缓存
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

bool GLWindow::dispose()
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

		// 大小写锁
		if (GetKeyState(VK_CAPITAL) & 1)
		{
			getKeyboard()->onKeyEvent(sys::BoardKey::KCAPITAL, sys::ButtonStatus::BUTTON_DOWN);
		}
		// 数字锁
		if (GetKeyState(VK_NUMLOCK) & 1)
		{
			getKeyboard()->onKeyEvent(sys::BoardKey::KNUMLOCK, sys::ButtonStatus::BUTTON_DOWN);
		}
	}
}
