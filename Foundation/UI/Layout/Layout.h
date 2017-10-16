#pragma once

#include "LayoutItem.h"

namespace ui
{
	/**
	*	界面布局
	*	外框大小改变时，调整内部结构，当内部结构达到临界值时，外框大小不能改变
	*	管理布局中的元件，当界面大小发生改变时，调整元件的位置和大小
	*/
	class Layout : public LayoutItem
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
		/**
		*	获取子元件元件
		*/
		const std::vector<LayoutItem*>& getChildren();
	public:
		/**
		*	当窗口大小发生改变时
		*/
		virtual void resize(const sys::Size& size);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const sys::Vector2& position, const sys::Size& size);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const sys::Rect& rect);
		/**
		*	复制对象
		*/
		bool copy(Layout* item);
		/**
		*	布局内部大小改变
		*	计算位置
		*/
		static void calLayoutPosition(LayoutItem* child, const sys::Size& srcSize, const sys::Size& newSize, float& x, float& y);
		/**
		*	布局内部大小改变
		*	计算大小
		*/
		static void calLayoutSize(LayoutItem* child, const sys::Size& srcSize, const sys::Size& newSize, float& w, float& h);
	protected:
		/**
		*	布局内部大小改变
		*	包含固定大小和百分比两种情况
		*	先计算固定大小的值，再计算百分比的值
		*/
		virtual void onLayoutSizeChanged(const sys::Size& innerSize);		
	protected:
		// 边缘距离
		sys::Margin m_fMargin;
		// 子元件集合
		std::vector<LayoutItem*> m_vChildren;		
	};
}