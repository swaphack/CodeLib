#pragma once

#include "DrawNode.h"

namespace render
{
	// ��
	class PointNode : public DrawNode
	{
	public:
		PointNode();
		virtual ~PointNode();
	public:
		virtual void draw();		
	};
}