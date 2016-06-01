#pragma once

#include "macros.h"

namespace render
{
	// ģ�� 
	// 2016-6-1 10:17:07 ��������
	class CtrlStencil : public ColorNode
	{
	public:
		CtrlStencil();
		virtual ~CtrlStencil();
	public:
		virtual void draw();
		virtual void visit();
		
		void setStencilNode(Node* node);
	protected:
		Node* _stencilNode;
		int _mask;
		static int g_mask;
	};
}