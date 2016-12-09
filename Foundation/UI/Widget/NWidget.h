#pragma once

#include "render.h"

#include "Widget.h"

namespace ui
{
	/**
	*	节点元件
	*/
	class NWidget : public Widget
	{
	public:
		NWidget(render::Node* node);
		virtual ~NWidget();
	public:
		virtual void onViewSizeChanged();
	private:
		// 渲染节点
		render::Node* m_pNode;
	};
}