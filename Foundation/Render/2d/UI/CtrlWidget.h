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
		// 点击是否命中
		virtual bool containTouchPoint(float x, float y);
	private:
		// 矩形框
		RectVertex _rectVertex;
	};
}