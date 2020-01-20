#pragma once

#include "Signal.h"
#include "KeyBoard.h"
#include "Mouse.h"

namespace sys
{
	class WindowImpl
	{
	public:
		virtual ~WindowImpl(){};
	public:
		// 窗口位置x
		virtual float getPositionX() = 0;
		// 窗口位置y
		virtual float getPositionY() = 0;
		// 窗口宽度
		virtual float getWidth() = 0;
		// 窗口高度
		virtual float getHeight() = 0;
		// 标题
		virtual std::string getTitle() = 0;
		// 接受信号的处理
		virtual bool onRecvSignal(Signal* signal) = 0;
	public:// 外设
		// 键盘
		virtual Keyboard* getKeyboard() = 0;
		// 鼠标
		virtual Mouse* getMouse() = 0;
	};
}