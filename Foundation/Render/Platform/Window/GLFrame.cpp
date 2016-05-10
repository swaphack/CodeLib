#include "GLFrame.h"

using namespace render;


GLFrame::GLFrame()
:_glrc(NULL),
_dc(NULL),
_bits(0),
_render(nullptr)
{

}

GLFrame::~GLFrame()
{

}

void GLFrame::initWindow(const char* title, int width, int height, int bits, RenderApplication* render)
{
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
	static PIXELFORMATDESCRIPTOR pfd =	// /pfd ���ߴ�ʹ�õ����ظ�ʽ
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// ������ʽ�������Ĵ�С
		1,											// �汾��
		PFD_DRAW_TO_WINDOW |                        // ��ʽ֧�ִ���
		PFD_SUPPORT_OPENGL |						// ��ʽ����֧��OpenGL
		PFD_DOUBLEBUFFER,							// ����֧��˫����
		PFD_TYPE_RGBA,								// ���� RGBA ��ʽ
		_bits,                                       // ѡ��ɫ�����
		0, 0, 0, 0, 0, 0,                           // ���Ե�ɫ��λ
		0,                                          // ��Alpha����
		0,                                          // ����Shift Bit
		0,                                          // ���ۼӻ���
		0, 0, 0, 0,                                 // ���Ծۼ�λ
		16,                                         // 16λ Z-���� (��Ȼ���)
		0,                                          // ���ɰ建��
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

bool GLFrame::dispose()
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

void GLFrame::listen()
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