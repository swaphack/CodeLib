#pragma once

#include "LayoutItemBase.h"
#include "macros.h"

namespace ui
{
	class CtrlWidget;
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
		static LayoutItem* create();
		/**
		*	设置留白距离
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	获取留白距离
		*/
		const sys::CSSMargin& getMargin() const;
		/**
		*	获取留白距离
		*/
		sys::CSSMargin& getMargin();
		/**
		*	设置留白状态
		*/
		void setMarginState(bool left, bool right, bool top, bool bottom);
		/**
		*	设置留白状态
		*/
		void setMarginState(const MarginState& state);
		/**
		*	获取留白状态
		*/
		const MarginState& getMarginState() const;
		/**
		*	获取留白状态
		*/
		MarginState& getMarginState();
		/**
		*	设置内部面积
		*/
		void setSize(const sys::CSSSize& size);
		/**
		*	获取内部面积
		*/
		const sys::CSSSize& getSize() const;
		/**
		*	获取内部面积
		*/
		sys::CSSSize& getSize();
	public:
		/**
		*	设置留白
		*/
		void setMargin(float top, float right, float bottom, float left);
		/**
		*	设置距离左边偏移量
		*/
		void setLeftMargin(float offset, bool enable = true);
		/**
		*	设置距离右边偏移量
		*/
		void setRightMargin(float offset, bool enable = true);
		/**
		*	设置距离顶部偏移量
		*/
		void setTopMargin(float offset, bool enable = true);
		/**
		*	设置距离底部偏移量
		*/
		void setBottomMargin(float offset, bool enable = true);
		/**
		*	取消距离左边偏移量设置
		*/
		void unsetLeftMargin();
		/**
		*	取消距离右边偏移量设置
		*/
		void unsetRightMargin();
		/**
		*	取消距离顶部偏移量设置
		*/
		void unsetTopMargin();
		/**
		*	取消距离底部偏移量设置
		*/
		void unsetBottomMargin();
		/**
		*	设置空白状态
		*/
		void unsetMarginState();
	public:
		/**
		*	设置宽度
		*/
		void setWidth(float value);
		/**
		*	设置高度
		*/
		void setHeight(float value);
	public: // 可能需重载的方法
		/**
		*	复制对象
		*/
		bool copy(LayoutItem* item);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const math::Size& size);
	public:
		/**
		*	添加控件
		*/
		void setWidget(CtrlWidget* widget);
	protected:
		// 留白距离
		sys::CSSMargin m_sMargin;
		// 留白距离
		sys::CSSSize m_sSize;
		// 留白状态
		MarginState m_sMarginState;
	};
}