#pragma once

#include "CtrlWidget.h"

namespace ui
{
	enum class StencilMode
	{
		// ��ģ������ʾ
		INCLUDE,
		// ��ģ������ʾ
		EXCLUDE,
	};
	/**
	*	ģ��
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
		/**
		*	����ģ��ڵ�
		*/
		void setStencilNode(Node* node);
		/**
		*	����ģ����ʾģʽ
		*/
		void setStencilMode(StencilMode mode);
	protected:
		virtual void beforeDrawNode();
		virtual void afterDrawNode();
	protected:
	private:
		Node* _stencilNode = nullptr;

		StencilMode _stencilMode = StencilMode::INCLUDE;
	};
}