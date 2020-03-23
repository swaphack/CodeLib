#pragma once

#include "system.h"
#include <windows.h>

namespace render
{
	class RenderApplication;
	class DeviceProxy;

	// gl窗口
	class GLWindow : public sys::Window
	{
	public:
		GLWindow();
		virtual ~GLWindow();
	public:
		void createWindow(const char* title, int width, int height, int millis, RenderApplication* render);
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