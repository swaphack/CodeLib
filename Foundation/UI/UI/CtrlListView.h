#pragma once

#include "CtrlScrollView.h"

namespace ui
{
	// 滑动方向
	enum class ScrollDirection
	{
		// 水平从左往右
		HORIZONTAL_LEFT_TO_RIGHT,
		// 水平从右往左
		HORIZONTAL_RIGHT_TO_LEFT,
		// 水平从上往下
		VERTICAL_TOP_TO_BOTTOM,
		// 水平从下往上
		VERTICAL_BOTTOM_TO_TOP,
	};

	// 列表
	class CtrlListView : public CtrlScrollView
	{
	public:
		CtrlListView();
		virtual ~CtrlListView();
	public:
		virtual bool init();
	public:
		/**
		*	设置滑动方向
		*/
		void setScrollDirection(ScrollDirection direction);
		/**
		*	获取滑动方向
		*/
		ScrollDirection getScrollDirection();
		/**
		*	设置项的大小
		*/
		void setItemSize(const math::Size& size);
		/**
		*	设置项的大小
		*/
		void setItemSize(float width, float height);
		/**
		*	获取设置项的大小
		*/
		const math::Size& getItemSize();
		/**
		*	是否使用配置大小
		*/
		bool isUseItemSize() const;
		/**
		*	是否使用配置大小
		*/
		void setUseItemSize(bool bUsed);
		/**
		*	是否居中显示
		*/
		bool isShowInCenter() const;
		/**
		*	是否居中显示
		*/
		void setShowInCenter(bool bCenter);
	public:
		/**
		*	添加一个项
		*/
		virtual void addItem(CtrlWidget* item, int zOrder = 0);
	protected:
		virtual bool onTouchMoved(float x, float y, bool include);
	protected:
		// 初始化滑动项
		virtual void initItems();
		// 初始化管理项
		virtual void initContent();
	protected:
		// 滑动方向
		ScrollDirection _scrollDirection = ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT;
		// 项的大小
		math::Size _itemSize;
		// 是否使用设置的大小
		bool _useItemSize = false;

		// 是否居中显示
		bool _showInCenter = false;
	};
}
