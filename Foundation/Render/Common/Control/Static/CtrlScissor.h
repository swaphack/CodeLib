#pragma once

#include "macros.h"

namespace render
{
	/**
	*	Ƭ�β��� 2dʹ��
	*/
	class CtrlScissor : public Node
	{
	public:
		CtrlScissor();
		virtual ~CtrlScissor();
	public:
		virtual void draw();
		virtual void visit();
	protected:
	private:
	};
}