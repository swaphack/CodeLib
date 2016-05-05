#pragma once

#include "DrawNode.h"

namespace render
{
	// µã
	class PointNode : public DrawNode
	{
	public:
		PointNode();
		virtual ~PointNode();
	public:
		virtual void draw();		
	};
}