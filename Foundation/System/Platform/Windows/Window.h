#pragma once

#include "Platform/macros.h"
#include "Base/Types.h"
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
		virtual void initWindow(const char* title, int32 width, int32 height);
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
		// 窗口句柄
		HWND _wnd;
		// 程序实例
		HINSTANCE _instance;
		// 窗口宽度
		float _width;
		// 窗口高度
		float _height;
		// 窗口x轴位置
		float _posX;
		// 窗口y轴位置
		float _posY;
		// 窗口标题
		std::string _title;
	protected:
		Keyboard* _keyboard;
		Mouse* _mouse;
	};

}