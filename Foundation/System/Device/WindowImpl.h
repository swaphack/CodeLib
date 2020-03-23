#pragma once

#include <string>
#include <cstdint>

namespace sys
{
	class WindowImpl
	{
	public:
		WindowImpl();
		virtual ~WindowImpl();
	public:
		void initWindow(const std::string& title, float width, float height, float posX, float posY);
	public:
		// 窗口位置x
		void setPositionX(float posX);
		// 窗口位置x
		float getPositionX();
		// 窗口位置y
		void setPositionY(float posY);
		// 窗口位置y
		float getPositionY();
		// 窗口高度
		void setWidth(float width);
		// 窗口宽度
		float getWidth();
		// 窗口高度
		void setHeight(float height);
		// 窗口高度
		float getHeight();
		// 标题
		void setTile(const std::string& name);
		// 标题
		std::string getTitle();
	protected:
		// 窗口宽度
		float _width = 0;
		// 窗口高度
		float _height = 0;
		// 窗口x轴位置
		float _posX = 0;
		// 窗口y轴位置
		float _posY = 0;
		// 窗口标题
		std::string _title;
	};
}