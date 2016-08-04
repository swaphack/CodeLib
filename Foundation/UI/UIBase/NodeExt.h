#pragma once

#include "macros.h"
#include "UIProtocol.h"

namespace ui
{
	// ui节点
	class NodeExt :
		public UINameProtocol,
		public UIBoxProtocol
	{
	public:
		NodeExt(render::Node* node);
		virtual ~NodeExt();
	public:
		virtual void draw();

		// 根据名称获取控件
		UINameProtocol* getChildByName(const char* name);
	public:
		// 开始绘制UI
		virtual void beginDraw();
		// 结束绘制
		virtual void afterDraw();
	private:
		render::Node* _pThis;
	};
}