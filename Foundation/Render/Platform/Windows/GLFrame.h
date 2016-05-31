#pragma once

#include "system.h"
#include <windows.h>

#include "../../Common/RenderApplication.h"

namespace render
{
	class RenderApplication;

	// �豸����
	class DeviceProxy : public sys::Object
	{
	public:
		DeviceProxy(const TouchManager* touchManager);
		~DeviceProxy();
	public:
		void onMouseButtonHandler(sys::MouseKey Key, sys::ButtonStatus type, float x, float y);

		void onMouseMoveHandler(float x, float y);

		void onKeyBoardButtonHandler(sys::BoardKey Key, sys::ButtonStatus type);
	protected:
	private:
		TouchManager* _touchManager;
	};

	// gl����
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
		// ��������
		virtual void initDevice();
	protected:
		// ������ɫ���������
		HGLRC _glrc;
		// OpenGL��Ⱦ���������
		HDC	_dc;
		// ���
		int _bits;
		// ��Ⱦ
		RenderApplication* _render;
		// �豸����
		DeviceProxy* _deviceProxy;
	};
}