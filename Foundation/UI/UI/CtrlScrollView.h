#pragma once

#include "CtrlWidget.h"
#include "CtrlLayout.h"
#include "Common/Input/TouchDelegate.h"

namespace ui
{
	class CtrlScrollView;

	class ScrollItem : public CtrlWidget
	{
	public:
		ScrollItem();
		virtual ~ScrollItem();
	public:
		// 添加项
		void addItem(CtrlWidget* node, const sys::CSSSize& size);

		void setScrollView(CtrlScrollView* view);

		const CtrlScrollView* getScrollView() const;
	public:
		static ScrollItem* create(CtrlWidget* node, const sys::CSSSize& size, CtrlScrollView* view);
	private:
		CtrlScrollView* _relativeView = nullptr;
	};

	// 滑动
	class CtrlScrollView : public CtrlLayout
	{
	public:
		CtrlScrollView();
		virtual ~CtrlScrollView();
	public:
		virtual bool init();
	public:
		/**
		*	设置内部大小
		*/
		void setInnerSize(const math::Size& size);
		/**
		*	内部大小
		*/
		math::Size getInnerSize();
		/**
		*	内部布局
		*/
		const CtrlLayout* getInner() const;
	public:
		/**
		*	添加一个项
		*/  
		virtual void addItem(CtrlWidget* item, int zOrder = 0);
		/**
		*	添加一个项, 并设置大小
		*/
		void addItem(CtrlWidget* item, const math::Size& size, int zOrder = 0);
		/**
		*	添加一个项, 并设置大小
		*/
		void addItem(CtrlWidget* item, const sys::CSSSize& size, int zOrder = 0);
		/**
		*	移除一个项
		*/ 
		void removeItem(CtrlWidget* item);
		/**
		*	移除所有项
		*/ 
		void removeAllItems();
	public:
		/**
		*	水平方向是否可以滑动
		*/
		bool isHorizontalScroll() const;
		/**
		*	设置水平方向是否可以滑动
		*/
		void setHorizontalScroll(bool scroll);
		/**
		*	垂直方向是否可以滑动
		*/
		bool isVerticalScroll() const;
		/**
		*	设置水平方向是否可以滑动
		*/
		void setVerticalScroll(bool scroll);
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
		// 管理所有项的位置
		CtrlLayout* _content = nullptr;
		// 项
		std::vector<ScrollItem*> _scrollItems;
		// 点击位置
		math::Vector2 _touchPosition;
		
		// 垂直方向是否可以滑动
		bool _bHorizontalScroll = true;
		// 水平方向是否可以滑动
		bool _bVerticalScroll = true;
	};
}