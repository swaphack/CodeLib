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
		// 初始化窗口
		virtual bool init();
		// 销毁窗口
		virtual bool dispose();
		// 监听窗口
		virtual void listen();
		// 接受信号的处理
		virtual bool onHandSignal(sys::Signal* signal);
	protected:
		// 窗口着色描述表句柄
		HGLRC _glrc;
		// OpenGL渲染描述表句柄
		HDC	_dc;
		// 深度
		int _bits;
		// 渲染
		RenderApplication* _render;
	};
}