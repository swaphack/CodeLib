#pragma once

#include "Node.h"

namespace render
{
	// ������ɫ�Ľڵ�
	class ColorNode :  
		public Node, 
		public ColorProtocol, 
		public BlendProtocol
	{
	public:
		ColorNode();
		virtual ~ColorNode();
	public:
		virtual void draw();
	};
}