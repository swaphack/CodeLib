#pragma once

namespace sys
{
	class WindowImpl
	{
	public:
		virtual ~WindowImpl() = 0;
	public:
		// 设置窗口位置
		virtual void setPosition(float x, float y) = 0;
		// 设置窗口大小
		virtual void setSize(float width, float height) = 0;
		// 设置标题
		virtual void setTitle(const char* title) = 0;
	};
}