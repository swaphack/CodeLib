#pragma once

#include "CtrlWidget.h"

namespace render
{
	/**
	*	Ä£°å
	*/
	class CtrlStencil : public CtrlWidget
	{
	public:
		CtrlStencil();
		virtual ~CtrlStencil();
	public:
		virtual bool init();
	public:
		void setFunc(StencilFunction func, int ref, uint32_t mask);
		void setOperator(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
	public:
		void setStencilNode(Node* node);
	protected:
		virtual void beforeDrawNode();
		virtual void afterDrawNode();
	protected:
	private:
		Node* _stencilNode = nullptr;
	};
}