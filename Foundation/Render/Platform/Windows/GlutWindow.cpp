#include "GlutWindow.h"
#include "ext-config.h"
#include "RenderApplication.h"
#include "Platform/DeviceProxy.h"
#include "system.h"
#include "Graphic/GLAPI/GLVersion.h"
#include "Common/Input/KeyChar.h"

using namespace render;
using namespace sys;

static GlutWindow* sWindow = nullptr;

GlutWindow::GlutWindow()
{
	_deviceProxy = new DeviceProxy();
	sWindow = this;
}

GlutWindow::~GlutWindow()
{
	SAFE_DELETE(_deviceProxy);
	SAFE_DELETE(_render);
}

void display()
{
	sWindow->onUpdate();

	glutSwapBuffers();
};

void update(int value)
{
	//sWindow->onUpdate();	

	glutPostRedisplay();

	glutTimerFunc(sWindow->getRefreshInterval() * 1000, ::update, value);
};

void keyboardDown(unsigned char key, int x, int y)
{
	sWindow->onKeyboardDown(key, x, y);
};

void keyboardUp(unsigned char key, int x, int y)
{
	sWindow->onKeyboardUp(key, x, y);
};

void mouseDown(int button, int state, int x, int y)
{
	sWindow->onMouseDown(button, state, x, y);
};

void mouseScroll(int button, int state, int x, int y)
{
	if (state == 1)
	{
		sWindow->onMouseScroll(0, 1);
	}
	else
	{
		sWindow->onMouseScroll(1, -1);
	}
	
}

void mouseMove(int x, int y)
{
	sWindow->onMouseMove(x, y);
};

void sizeChange(int width, int height)
{
	sWindow->onSizeChange(width, height);
};

void GlutWindow::createWindow(const std::string& title, int width, int height, int millis, RenderApplication* render)
{
	if (render == nullptr)
	{
		return;
	}

	int mode = GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL;
	int left = (GetSystemMetrics(SM_CXSCREEN) - width)* 0.5f;
	int top = (GetSystemMetrics(SM_CYSCREEN) - height)* 0.5f;
	
	this->initWindow(title, width, height, left, top);
	_render = render;
	_render->setRefreshInterval(millis / 1000.0f);
	_render->init();
	_render->setFrameSize((int)getWidth(), (int)getHeight());

	glutInitDisplayMode(mode);
	glutInitWindowPosition(left, top);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());

	int err = glewInit();
	if (GLEW_OK != err)
	{
		PRINT("Error [main]: glewInit failed: %s\n", glewGetErrorString(err));
		return;
	}

	GLVersion::showDetail();

	glutKeyboardFunc(::keyboardDown);
	glutKeyboardUpFunc(::keyboardUp);
	glutMouseFunc(::mouseDown);
	glutMotionFunc(::mouseMove);
	glutMouseWheelFunc(::mouseScroll);
	glutReshapeFunc(::sizeChange);
	

	_render->show();
	this->initDevice();

	glutDisplayFunc(::display);
	glutTimerFunc(millis, ::update, 1);

	glutMainLoop();
}

void GlutWindow::initDevice()
{
	if (getMouse())
	{
		getMouse()->setButtonHandler(_deviceProxy, MOUSE_BUTTON_SELECTOR(DeviceProxy::onMouseButtonHandler));
		getMouse()->setMoveHandler(_deviceProxy, MOUSE_MOVE_SELECTOR(DeviceProxy::onMouseMoveHandler));
		getMouse()->setScrollHandler(_deviceProxy, MOUSE_SCROLL_SELECTOR(DeviceProxy::onMouseScrollHandler));
	}

	if (getKeyboard())
	{
		getKeyboard()->setKeyhandler(_deviceProxy, KEYBOARD_BUTTON_SELECTOR(DeviceProxy::onKeyBoardButtonHandler));

		// ´óÐ¡Ð´Ëø
		if (GetKeyState(VK_CAPITAL) & 1)
		{
			getKeyboard()->onKeyEvent(sys::BoardKey::KCAPITAL, sys::ButtonStatus::BUTTON_DOWN);
		}
		// Êý×ÖËø
		if (GetKeyState(VK_NUMLOCK) & 1)
		{
			getKeyboard()->onKeyEvent(sys::BoardKey::KNUMLOCK, sys::ButtonStatus::BUTTON_DOWN);
		}
	}
}

void GlutWindow::onUpdate()
{
	if (_render)
	{
		_render->update();
	}
}

void GlutWindow::onKeyboardDown(unsigned char key, int x, int y)
{
	_deviceProxy->onKeyBoardButtonHandler(G_KEYCHAR->getKey(key), sys::ButtonStatus::BUTTON_DOWN);
}

void GlutWindow::onKeyboardUp(unsigned char key, int x, int y)
{
	_deviceProxy->onKeyBoardButtonHandler(G_KEYCHAR->getKey(key), sys::ButtonStatus::BUTTON_UP);
}

void GlutWindow::onMouseDown(int button, int state, int x, int y)
{
	_deviceProxy->onMouseButtonHandler((sys::MouseKey)button, (sys::ButtonStatus)state, x, y);
}

void GlutWindow::onMouseMove(int x, int y)
{
	_deviceProxy->onMouseMoveHandler(x, y);
}

void render::GlutWindow::onMouseScroll(int evt, int value)
{
	_deviceProxy->onMouseScrollHandler((sys::ScrollEvent)evt, value);
}

void GlutWindow::onSizeChange(int width, int height)
{
	if (_render)
	{
		_render->setFrameSize(width, height);
	}
}

float GlutWindow::getRefreshInterval()
{
	if (_render)
	{
		return _render->getRefreshInterval();
	}

	return 0;
}

