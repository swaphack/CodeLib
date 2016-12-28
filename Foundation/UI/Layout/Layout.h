#pragma once

#include "system.h"

#include "LayoutItem.h"

namespace ui
{
	/**
	*	界面布局
	*	所有布局中的项均为水平居中
	*	外框大小改变时，调整内部结构，当内部结构达到临界值时，外框大小不能改变
	*	管理布局中的元件，当界面大小发生改变时，调整元件的位置和大小
	*/
	class Layout : public render::Node, public LayoutItem
	{
	public:
		Layout();
		virtual ~Layout();
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
		void addItem(LayoutItem* item);
		/**
		*	移除一个元件
		*/
		void removeItem(LayoutItem* item);
		/**
		*	移除所有元件
		*/
		void removeAllItems();
	public:
		/**
		*	当窗口大小发生改变时
		*/
		virtual void resize(const sys::Size& inputSize);
		/**
		*	获取布局的最小面积
		*/
		virtual sys::Size getLayoutItemMinSize();
		/**
		*	获取布局的最大面积
		*/
		virtual sys::Size getLayoutItemMaxSize();
	protected:
		/**
		*	获取布局内部的最小面积
		*/
		virtual sys::Size getLayoutInnerMinSize() = 0;
		/**
		*	获取布局内部的最大面积
		*/
		virtual sys::Size getLayoutInnerMaxSize() = 0;
		/**
		*	布局内部大小改变
		*	包含固定大小和百分比两种情况
		*	先计算固定大小的值，再计算百分比的值
		*/
		virtual void onLayoutInnerSizeChanged(const sys::Size& innerSize);
		/**
		*	计算布局项宽度
		*/
		virtual float calItemWidth(LayoutItem* item, float width);
		/**
		*	计算布局项宽度
		*/
		virtual float calItemHeight(LayoutItem* item, float height);
	protected:
		// 边缘距离
		sys::Margin m_fMargin;
		// 子元件集合
		std::vector<LayoutItem*> m_vChildren;		
	};

	/**
	*	水平布局, 从左到右计算坐标
	*/
	class HorizontalLayout : public Layout
	{
	public:
		HorizontalLayout();
		virtual ~HorizontalLayout();
	public:
		/**
		*	获取布局内部的最小面积
		*/
		virtual sys::Size getLayoutInnerMinSize();
		/**
		*	获取布局内部的最大面积
		*/
		virtual sys::Size getLayoutInnerMaxSize();
	};

	/** 
	*	垂直布局, 从下到上计算坐标
	*/
	class VerticalLayout : public Layout
	{
	public:
		VerticalLayout();
		virtual ~VerticalLayout();
	public:
		/**
		*	获取布局的最小面积
		*/
		virtual sys::Size getLayoutItemMinSize();
		/**
		*	获取布局的最大面积
		*/
		virtual sys::Size getLayoutItemMaxSize();
	};

	// 格子布局
	class GridLayout : public Layout
	{
	public:
		GridLayout();
		virtual ~GridLayout();
	public:
		/**
		*	获取布局的最小面积
		*/
		virtual sys::Size getLayoutItemMinSize();
		/**
		*	获取布局的最大面积
		*/
		virtual sys::Size getLayoutItemMaxSize();
	};
}