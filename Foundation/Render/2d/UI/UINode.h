#pragma once

#include "macros.h"
#include "UIProtocol.h"

namespace render
{
	// ui节点
	class UINode : public Node, public UINameProtocol, public UIBoxProtocol
	{
	public:
		UINode();
		virtual ~UINode();
	public:
		// 绘制
		virtual void draw();
		// 根据名称获取控件
		UINameProtocol* getChildByName(const char* name);
	protected:
		// 开始绘制UI
		virtual void beginDrawUI();
		// 结束绘制
		virtual void afterDrawUI();
	};
}