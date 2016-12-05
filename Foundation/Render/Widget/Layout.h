#pragma once

#include "Widget.h"

namespace render
{
	// ���沼��
	class Layout : public Widget
	{
	public:
		Layout();
		virtual ~Layout();
	public:
		virtual bool init();
		// ���ò��ִ�С
		void setLayoutSize(float width, float height);
		// ���ڴ�С�ı�ʱ����
		void updateViewSize(float width, float height);
		// ���²���
		void updateLayout();
	protected:
		// ���ִ�С
		sys::Size _layoutSize;
		// ����x�����ű�
		float _layoutScaleX;
		// ����Y�����ű�
		float _layoutScaleY;
		// ����Ԫ��������ű�
		float _layoutContentScale;
	};
}