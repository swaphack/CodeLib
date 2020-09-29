#pragma once

#include "LayoutItemBase.h"

namespace ui
{
	/**
	*	布局项, 抽象类
	*	布局项的集合信息在界面调整中不做改变，改变的只有CtrlWidget的集合信息
	*/
	class LayoutItem : public LayoutItemBase
	{
	public:
		LayoutItem();
		virtual ~LayoutItem();
	public:
		/**
		*	设置边缘距离
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	获取边缘距离
		*/
		const sys::CSSMargin& getMargin() const;
		/**
		*	设置内部面积
		*/
		void setSize(const sys::CSSSize& size);
		/**
		*	获取内部面积
		*/
		const sys::CSSSize& getSize() const;
	public: // 可能需重载的方法
		/**
		*	复制对象
		*/
		bool copy(LayoutItem* item);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const math::Size& size);
	
	protected:
		// 边缘距离
		sys::CSSMargin m_sMargin;
		// 边缘距离
		sys::CSSSize m_sSize;
	};
}