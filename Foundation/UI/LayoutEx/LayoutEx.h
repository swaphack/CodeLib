#pragma once

#include "LayoutItemEx.h"

namespace ui
{
	/**
	*	界面布局
	*	外框大小改变时，调整内部结构，当内部结构达到临界值时，外框大小不能改变
	*	管理布局中的元件，当界面大小发生改变时，调整元件的位置和大小
	*/
	class LayoutEx : public LayoutItemEx
	{
	public:
		LayoutEx();
		virtual ~LayoutEx();
	public:
		/**
		*	设置左边缘距离
		*/
		void setLeftMargin(float margin);
		/**
		*	获取左边缘距离
		*/
		float getLeftMargin();
		/**
		*	设置右边缘距离
		*/
		void setRightMargin(float margin);
		/**
		*	获取右边缘距离
		*/
		float getRightMargin();
		/**
		*	设置上边缘距离
		*/
		void setTopMargin(float margin);
		/**
		*	获取上边缘距离
		*/
		float getTopMargin();
		/**
		*	设置下边缘距离
		*/
		void setBottomMargin(float margin);
		/**
		*	获取左边缘距离
		*/
		float getBottomMargin();
		/**
		*	设置边缘距离
		*/
		void setMargin(const sys::Margin& margin);
		/**
		*	获取边缘距离
		*/
		const sys::Margin& getMargin();
		/**
		*	添加一个元件
		*/
		void addItem(LayoutItemEx* item);
		/**
		*	移除一个元件
		*/
		void removeItem(LayoutItemEx* item);
		/**
		*	移除所有元件
		*/
		void removeAllItems();
		/**
		*	获取子元件元件
		*/
		const std::vector<LayoutItemEx*>& getChildren();
	public:
		/**
		*	当窗口大小发生改变时
		*/
		virtual void resize(const math::Size& size);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const math::Vector2& position, const math::Size& size);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const math::Rect& rect);
		/**
		*	获取布局的最小面积
		*/
		virtual math::Size getLayoutMinSize();
		/**
		*	获取布局的最大面积
		*/
		virtual math::Size getLayoutMaxSize();
		/**
		*	复制对象
		*/
		virtual bool copy(LayoutEx* item);
	protected:
		/**
		*	获取布局内部的最小面积
		*/
		virtual math::Size getLayoutInnerMinSize();
		/**
		*	获取布局内部的最大面积
		*/
		virtual math::Size getLayoutInnerMaxSize();
		/**
		*	布局内部大小改变
		*	包含固定大小和百分比两种情况
		*	先计算固定大小的值，再计算百分比的值
		*/
		virtual void onLayoutSizeChanged(const math::Size& innerSize);
		/**
		*	计算布局项宽度
		*/
		virtual float calItemWidth(LayoutItemEx* item, float width);
		/**
		*	计算布局项宽度
		*/
		virtual float calItemHeight(LayoutItemEx* item, float height);
	protected:
		// 边缘距离
		sys::Margin m_fMargin;
		// 子元件集合
		std::vector<LayoutItemEx*> m_vChildren;
	};

	/**
	*	水平布局, 从左到右计算坐标
	*/
	class HorizontalLayout : public LayoutEx
	{
	public:
		HorizontalLayout();
		virtual ~HorizontalLayout();
	public:
		/**
		*	获取布局内部的最小面积
		*/
		virtual math::Size getLayoutInnerMinSize();
		/**
		*	获取布局内部的最大面积
		*/
		virtual math::Size getLayoutInnerMaxSize();
	};

	/** 
	*	垂直布局, 从下到上计算坐标
	*/
	class VerticalLayout : public LayoutEx
	{
	public:
		VerticalLayout();
		virtual ~VerticalLayout();
	public:
		/**
		*	获取布局的最小面积
		*/
		virtual math::Size getLayoutInnerMinSize();
		/**
		*	获取布局的最大面积
		*/
		virtual math::Size getLayoutInnerMaxSize();
	};

	// 格子布局
	class GridLayout : public LayoutEx
	{
	public:
		GridLayout();
		virtual ~GridLayout();
	public:
		/**
		*	获取布局的最小面积
		*/
		virtual math::Size getLayoutInnerMinSize();
		/**
		*	获取布局的最大面积
		*/
		virtual math::Size getLayoutInnerMaxSize();
	};
}