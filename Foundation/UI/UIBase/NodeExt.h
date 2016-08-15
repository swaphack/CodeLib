#pragma once

#include "macros.h"
#include "UIProtocol.h"

namespace ui
{
	#define NODE_EXT_ZORDER INT_MAX
	// ui扩张，用于显示外框
	class NodeExt :
		public render::Node,
		public UIBoxProtocol
	{
	public:
		NodeExt(render::Node* parent);
		virtual ~NodeExt();
	public:
		virtual void draw();
	private:
		render::Node* _parent;
	};
}