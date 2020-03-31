#pragma once

#include "Common/Node/Node.h"
#include "mathlib.h"

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
	private:
		math::Rect makeRect();
	private:
		static int s_nScissorCount;
		static math::Rect s_rect;
	};
}