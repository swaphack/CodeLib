#pragma once

#include "Node.h"

namespace render
{
	// ������ɫ�Ľڵ�
	class ColorNode :  public Node, public ColorProtocol
	{
	public:
		ColorNode();
		virtual ~ColorNode();
	protected:
	private:
	};
}