#pragma once

#include "render.h"

namespace ui
{
	enum class StencilMode
	{
		// 在模板内显示
		INCLUDE,
		// 在模板外显示
		EXCLUDE,
	};
	/**
	*	模板
	*/
	class CtrlStencil : public render::DrawNode
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
		*	设置模板节点
		*/
		void setStencilNode(render::Node* node);
		/**
		*	设置模板显示模式
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