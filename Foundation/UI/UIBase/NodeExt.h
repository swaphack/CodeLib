#pragma once

#include "macros.h"
#include "UIProtocol.h"

namespace ui
{
	// ui扩张，用于显示外框
	class NodeExt :
		public render::Node,
		public UIBoxProtocol
	{
	public:
		NodeExt(render::Node* node);
		virtual ~NodeExt();
	public:
		virtual void draw();
	public:
		// 开始绘制UI
		virtual void beginDraw();
		// 结束绘制
		virtual void afterDraw();
	private:
		render::Node* _pThis;
	};
}