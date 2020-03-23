#pragma once

#include "system.h"
#include <windows.h>

namespace render
{
	class RenderApplication;
	class DeviceProxy;

	// gl����
	class GLWindow : public sys::Window
	{
	public:
		GLWindow();
		virtual ~GLWindow();
	public:
		void createWindow(const char* title, int width, int height, int millis, RenderApplication* render);
	protected:
		// ��ʼ������
		virtual bool init();
		// ���ٴ���
		virtual bool dispose();
		// ��������
		virtual void listen();
		// �����źŵĴ���
		virtual bool onHandSignal(sys::Signal* signal);
		// ��������
		virtual void initDevice();
	protected:
		// ������ɫ��������
		HGLRC _glrc;
		// OpenGL��Ⱦ��������
		HDC	_dc;
		// ���
		int _bits;
		// ��Ⱦ
		RenderApplication* _render;
		// �豸����
		DeviceProxy* _deviceProxy;
	};
}