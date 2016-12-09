#pragma once

#include "render.h"

#include "Widget.h"

namespace ui
{
	/**
	*	�ڵ�Ԫ��
	*/
	class NWidget : public Widget
	{
	public:
		NWidget(render::Node* node);
		virtual ~NWidget();
	public:
		virtual void onViewSizeChanged();
	private:
		// ��Ⱦ�ڵ�
		render::Node* m_pNode;
	};
}