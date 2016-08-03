#pragma once

#include "macros.h"

namespace render
{
	// ui 控件名称
	class UINameProtocol
	{
	public:
		UINameProtocol();
		virtual ~UINameProtocol();
	public:
		// 设置名称
		void setName(const char* name);
		// 获取名称
		const char* getName();
	private:
		// ui控件名称
		std::string _name;
	};

	// ui 控件显示区域
	class UIBoxProtocol
	{
	public:
		UIBoxProtocol();
		virtual ~UIBoxProtocol();
	public:
		// 设置矩形框是否可见
		void setBoxVisible(bool status);
		// 矩形框是否可见
		bool isBoxVisible();
		// 设置矩形框显示颜色
		void setBoxColor(const sys::Color4B& color);
		// 获取矩形框显示颜色
		const sys::Color4B& getBoxColor();
	private:
		// 矩形框颜色
		sys::Color4B _rectColor;
		// 是否显示矩形框
		bool _bBoxVisible;
	};
}