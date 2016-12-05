#pragma once

#include "macros.h"

namespace render
{
	// Ԫ��
	class Widget : public Node
	{
	public:
		Widget();
		~Widget();
	public:
		// ����Ԫ��ˮƽ���뷽ʽ
		void setHorizontalAlign(HorizontalAlignment alignment);
		// ��ȡԪ��ˮƽ���뷽ʽ
		HorizontalAlignment getHorizontalAlign();
		// ����Ԫ����ֱ���뷽ʽ
		void setVerticalAlign(VerticalAlignment alignment);
		// ��ȡԪ����ֱ���뷽ʽ
		VerticalAlignment getVerticalAlign();

		// ����ˮƽƫ�ƾ���
		void setOffsetX(float distance);
		// ��ȡˮƽƫ�ƾ���
		float getOffsetX();
		// ���ô�ֱƫ�ƾ���
		void setOffsetY(float distance);
		// ��ȡ��ֱƫ�ƾ���
		float getOffsetY();

		// ���ñ߿��Ƿ�ɼ�
		void setBoundBoxVisible(bool visible);
		// �߿��Ƿ�ɼ�
		bool isBoundBoxVisible();

		// ����Ԫ��
		void build(float scaleX, float scaleY, float contentScale);
	protected:
		virtual void updateTranform();
	protected:
		// ˮƽ���뷽ʽ
		HorizontalAlignment _widgetHorizontalAlignment;
		// ˮƽƫ�ƾ���
		float _offsetX;
		// ��ֱ���뷽ʽ
		VerticalAlignment _widgetVerticalAlignment;
		// ˮƽƫ�ƾ���
		float _offsetY;
		// �߿��Ƿ�ɼ�
		bool _bBoundBoxVisible;
		// Ԫ�����ű�
		float _contentScale;
	};
}