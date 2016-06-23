#pragma once

#include "macros.h"

namespace render
{
	// ui节点
	class UINode : public Node
	{
	public:
		UINode();
		virtual ~UINode();
	public:
		// 绘制
		virtual void draw();
		// 设置矩形框是否可见
		void setRectVisible(bool status);
		// 获取矩形框是否可见
		bool isRectVisible();
		// 设置矩形框显示颜色
		void setRectColor(const sys::Color4B& color);
		// 获取矩形框显示颜色
		sys::Color4B getRectColor();
		// 设置名称
		void setName(const char* name);
		// 获取名称
		const char* getName();
		// 根据名称获取控件
		UINode* getChildByName(const char* name);
	protected:
		// 开始绘制UI
		virtual void beginDrawUI();
		//  绘制UI
		virtual void onDrawUI();
		// 结束绘制
		virtual void afterDrawUI();
		// 显示绘制区域
		void drawRect();
	private:
		// 矩形框颜色
		sys::Color4B _rectColor;
		// 是否显示矩形框
		bool _bShowRect;
		// ui控件名称
		std::string _name;
	};
}