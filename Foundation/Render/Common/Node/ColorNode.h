#pragma once

#include "Node.h"

namespace render
{
	// 带有颜色的节点
	class ColorNode :  
		public Node, 
		public ColorProtocol, 
		public OpacityProtocol,
		public BlendProtocol
	{
	public:
		ColorNode();
		virtual ~ColorNode();
	public:
		virtual void draw();
	};
}