#pragma once

#include "Widget.h"

namespace render
{
	// 界面布局
	class Layout : public Widget
	{
	public:
		Layout();
		virtual ~Layout();
	public:
		virtual bool init();
		// 设置布局大小
		void setLayoutSize(float width, float height);
		// 窗口大小改变时处理
		void updateViewSize(float width, float height);
		// 更新布局
		void updateLayout();
	protected:
		// 布局大小
		sys::Size _layoutSize;
		// 界面x轴缩放比
		float _layoutScaleX;
		// 界面Y轴缩放比
		float _layoutScaleY;
		// 界面元件体积缩放比
		float _layoutContentScale;
	};
}