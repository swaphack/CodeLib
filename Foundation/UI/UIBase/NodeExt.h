#pragma once

#include "macros.h"
#include "UIProtocol.h"

namespace ui
{
	#define NODE_EXT_ZORDER INT_MAX
	// ui���ţ�������ʾ���
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