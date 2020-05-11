#pragma once

#include "Common/Node/ColorNode.h"

namespace render
{
	class Material;

	class CtrlWidget : public ColorNode
	{
	public:
		CtrlWidget();
		virtual ~CtrlWidget();
	public:
		virtual bool init();
	public:
		const RectVertex& getRectVertex();
		// ����Ƿ�����
		virtual bool containTouchPoint(float x, float y);
	protected:
		void calRectData();
	protected:
		// ���ο�
		RectVertex _rectVertex;
		// ʵ�ʾ��ο�
		RectVertex _realRectVertex;
	};
}