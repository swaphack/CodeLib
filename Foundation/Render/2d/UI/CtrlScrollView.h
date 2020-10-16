#pragma once

#include "CtrlWidget.h"
#include "CtrlLayout.h"
#include "Common/Input/TouchDelegate.h"

namespace render
{
	// 滑动方向
	enum class ScrollDirection
	{
		NONE = -1,
		// 水平从左往右
		HORIZONTAL_LEFT_TO_RIGHT,
		// 水平从右往左
		HORIZONTAL_RIGHT_TO_LEFT,
		// 水平从上往下
		VERTICAL_TOP_TO_BOTTOM,
		// 水平从下往上
		VERTICAL_BOTTOM_TO_TOP,
	};

	class ScrollItem : public CtrlWidget
	{
	public:
		ScrollItem();
		virtual ~ScrollItem();
	public:
		// 添加项
		void addItem(Node* node, const math::Size& size);

	public:
		static ScrollItem* create(Node* node, const math::Size& size);
	};

	// 滑动
	class CtrlScrollView : public CtrlLayout
	{
	public:
		CtrlScrollView();
		virtual ~CtrlScrollView();
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
		*	添加一个项
		*/  
		void addItem(CtrlWidget* item, int zOrder = 0);
		/**
		*	添加一个项, 并设置大小
		*/
		void addItem(CtrlWidget* item, const math::Size& size, int zOrder = 0);
		/**
		*	移除一个项
		*/ 
		void removeItem(CtrlWidget* item);
		/**
		*	移除所有项
		*/ 
		void removeAllItems();
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
	public:// 重写
		virtual void addWidget(CtrlWidget* item);
		virtual void addWidget(CtrlWidget* item, int zOrder);
		virtual void removeWidget(CtrlWidget* item);
		virtual void removeAllWidgets();
	protected:
		// 触摸处理
		virtual bool onTouchBegan(float x, float y, bool include);
		virtual bool onTouchMoved(float x, float y, bool include);
		virtual bool onTouchEnded(float x, float y, bool include);
	protected:
		// 初始化滑动项
		virtual void initItems();
		// 初始化管理项
		virtual void initContent();
	protected:
		// 滑动方向
		ScrollDirection _scrollDirection = ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT;
		// 管理所有项的位置
		CtrlLayout* _content = nullptr;
		// 项
		std::vector<CtrlWidget*> _itemWidgets;
		// 点击位置
		math::Vector2 _touchPosition;
		// 项的大小
		math::Size _itemSize;
	};
}