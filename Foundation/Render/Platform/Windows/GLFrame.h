#pragma once

#include "system.h"
#include <windows.h>

#include "KeyboardManager.h"
#include "../../Common/RenderApplication.h"

namespace render
{
	class RenderApplication;
	#define G_KEYBOARDMANAGER sys::Instance<KeyboardManager>::getInstance()

	// 设备代理
	class DeviceProxy : public sys::Object
	{
	public:
		DeviceProxy(const TouchManager* touchManager);
		~DeviceProxy();
	public:
		void onMouseButtonHandler(sys::MouseKey key, sys::ButtonStatus type, float x, float y);

		void onMouseMoveHandler(float x, float y);

		void onKeyBoardButtonHandler(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		// 触摸事件
		TouchManager* _touchManager;
		// 键盘事件
		KeyboardManager* _keyboardManager;
	};

	// gl窗口
	class GLFrame : public sys::Window
	{
	public:
		GLFrame();
		virtual ~GLFrame();
	public:
		virtual void initWindow(const char* title, int width, int height, int bits, RenderApplication* render);
	protected:
		// 初始化窗口
		virtual bool init();
		// 销毁窗口
		virtual bool dispose();
		// 监听窗口
		virtual void listen();
		// 接受信号的处理
		virtual bool onHandSignal(sys::Signal* signal);
		// 重置外设
		virtual void initDevice();
	protected:
		// 窗口着色描述表句柄
		HGLRC _glrc;
		// OpenGL渲染描述表句柄
		HDC	_dc;
		// 深度
		int _bits;
		// 渲染
		RenderApplication* _render;
		// 设备代理
		DeviceProxy* _deviceProxy;
	};
}