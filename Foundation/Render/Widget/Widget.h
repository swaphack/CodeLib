#pragma once

#include "macros.h"

namespace render
{
	// 元件
	class Widget : public Node
	{
	public:
		Widget();
		~Widget();
	public:
		// 设置元件水平对齐方式
		void setHorizontalAlign(HorizontalAlignment alignment);
		// 获取元件水平对齐方式
		HorizontalAlignment getHorizontalAlign();
		// 设置元件垂直对齐方式
		void setVerticalAlign(VerticalAlignment alignment);
		// 获取元件垂直对齐方式
		VerticalAlignment getVerticalAlign();

		// 设置水平偏移距离
		void setOffsetX(float distance);
		// 获取水平偏移距离
		float getOffsetX();
		// 设置垂直偏移距离
		void setOffsetY(float distance);
		// 获取垂直偏移距离
		float getOffsetY();

		// 设置边框是否可见
		void setBoundBoxVisible(bool visible);
		// 边框是否可见
		bool isBoundBoxVisible();

		// 构建元件
		void build(float scaleX, float scaleY, float contentScale);
	protected:
		virtual void updateTranform();
	protected:
		// 水平对齐方式
		HorizontalAlignment _widgetHorizontalAlignment;
		// 水平偏移距离
		float _offsetX;
		// 垂直对齐方式
		VerticalAlignment _widgetVerticalAlignment;
		// 水平偏移距离
		float _offsetY;
		// 边框是否可见
		bool _bBoundBoxVisible;
		// 元件缩放比
		float _contentScale;
	};
}