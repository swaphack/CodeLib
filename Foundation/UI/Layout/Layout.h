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
		*	获取子元件
		*/
		const std::vector<LayoutItem*>& getChildren() const;
		/**
		*	查找子元件
		*/
		LayoutItem* findItemByName(const std::string& name) const;
	public:
		/**
		*	当窗口大小发生改变时
		*/
		virtual void resize(const math::Size& size);
		/**
		*	复制对象
		*/
		bool copy(Layout* item);
	protected:
		/**
		*	布局内部大小改变
		*	包含固定大小和百分比两种情况
		*	先计算固定大小的值，再计算百分比的值
		*/
		virtual void onLayoutSizeChanged(const math::Size& innerSize);		
	protected:
		// 子元件集合
		std::vector<LayoutItem*> m_vChildren;		
	};
}