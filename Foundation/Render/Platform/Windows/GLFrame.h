#pragma once

#include "system.h"
#include <windows.h>

#include "../../Common/RenderApplication.h"

namespace render
{
	class RenderApplication;

	class GLFrame : public sys::Window
	{
	public:
		GLFrame();
		virtual ~GLFrame();
	public:
		virtual void initWindow(const char* title, int width, int height, int bits, RenderApplication* render);
	protected:
		// ��ʼ������
		virtual bool init();
		// ���ٴ���
		virtual bool dispose();
		// ��������
		virtual void listen();
		// �����źŵĴ���
		virtual bool onHandSignal(sys::Signal* signal);
	protected:
		// ������ɫ��������
		HGLRC _glrc;
		// OpenGL��Ⱦ��������
		HDC	_dc;
		// ���
		int _bits;
		// ��Ⱦ
		RenderApplication* _render;
	};
}