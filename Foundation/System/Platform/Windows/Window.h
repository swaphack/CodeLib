#pragma once

#include "Platform/macros.h"

#include <windows.h>

namespace sys
{
	// windows 窗口
	class Window : public WindowImpl, public DeviceImpl
	{
	public:
		Window();
		virtual ~Window();
	public:
		void initWindow(const std::string& title, int32_t width, int32_t height);
	public:
		// 窗口句柄
		inline HWND getWnd() { return _wnd; }
		// 接受信号的处理
		virtual bool onRecvSignal(const Signal* signal);
	protected:
		// 初始化窗口
		virtual bool init();
		// 销毁窗口
		virtual bool dispose();
		// 监听窗口
		virtual void listen();
		// 处理接收到的信息
		virtual bool onHandSignal(const Signal* signal);
	protected:
		// 窗口句柄
		HWND _wnd;
		// 程序实例
		HINSTANCE _instance;
	
	};

}