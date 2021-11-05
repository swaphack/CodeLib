#pragma once

#include "CtrlScrollView.h"

namespace ui
{

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
		*	设置项的大小
		*/
		void setItemSize(const sys::CSSSize& size);
		/**
		*	设置项的大小
		*/
		void setItemSize(float width, float height);
		/**
		*	获取设置项的大小
		*/
		const sys::CSSSize& getItemSize();
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
		// 处理触摸
		virtual void handMovedTouch(const math::Vector2& touchPoint);
	protected:
		// 初始化滑动项
		virtual void initItems();
		// 初始化管理项
		virtual void initContent();
	protected:
		// 项的大小
		sys::CSSSize _itemSize;
		// 是否使用设置的大小
		bool _useItemSize = false;

		// 是否居中显示
		bool _showInCenter = false;
	};
}
