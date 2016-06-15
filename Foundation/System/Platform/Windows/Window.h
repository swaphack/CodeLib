#pragma once

#include "../macros.h"
#include <string>
#include <windows.h>

namespace sys
{
	// windows 窗口
	class Window : public WindowImpl
	{
	public:
		Window();
		virtual ~Window();
	public:
		virtual void initWindow(const char* title, int width, int height);
	public:
		// 窗口句柄
		inline HWND getWnd() { return _wnd; }
		// 窗口位置x
		virtual float getPositionX() { return _posX; }
		// 窗口位置y
		virtual float getPositionY() { return _posY; }
		// 窗口宽度
		virtual float getWidth() { return _width; }
		// 窗口高度
		virtual float getHeight() { return _height;  }
		// 标题
		virtual const char* getTitle() { return _title.c_str(); }
		// 接受信号的处理
		virtual bool onRecvSignal(Signal* signal);
	public:// 外设
		// 键盘
		virtual Keyboard* getKeyboard();
		// 鼠标
		virtual Mouse* getMouse();
	protected:
		// 初始化窗口
		virtual bool init();
		// 销毁窗口
		virtual bool dispose();
		// 监听窗口
		virtual void listen();
		// 处理接收到的信息
		virtual bool onHandSignal(Signal* signal);
	protected:
		// 保存我们的窗口句柄
		HWND _wnd;
		// 保存程序的实例
		HINSTANCE _instance;
		float _width;
		float _height;
		float _posX;
		float _posY;
		std::string _title;
	protected:
		Keyboard* _keyboard;
		Mouse* _mouse;
	};

}