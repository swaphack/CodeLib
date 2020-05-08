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

	public:
		const RectVertex& getRectVertex();
		// ����Ƿ�����
		virtual bool containTouchPoint(float x, float y);
	private:
		// ���ο�
		RectVertex _rectVertex;
	};
}