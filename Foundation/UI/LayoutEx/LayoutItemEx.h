#pragma once

#include "Layout/LayoutItem.h"
#include "system.h"
#include "Layout/ui_common.h"

namespace ui
{
	class Layout;

	static const int LAYOUT_SIZE_MIN_WIDTH = 0;
	static const int LAYOUT_SIZE_MIN_HEIGHT = 0;
	static const int LAYOUT_SIZE_MAX_WIDTH = 65536;
	static const int LAYOUT_SIZE_MAX_HEIGHT = 65536;

	/**
	*	布局项, 抽象类
	*	布局项的集合信息在界面调整中不做改变，改变的只有Widget的集合信息
	*/
	class LayoutItemEx : public LayoutItem
	{
	public:
		LayoutItemEx();
		virtual ~LayoutItemEx();
	public: // 固定不变的数据
		/**
		*	获取最小长宽的信息
		*/
		const math::Size& getMinSize();
		/**
		*	设置最小长宽的信息
		*/
		void setMinSize(float width, float height);
		/**
		*	设置最小长宽的信息
		*/
		void setMinSize(const math::Size& size);
		/**
		*	获取最大长宽的信息
		*/
		const math::Size& getMaxSize();
		/**
		*	设置最大长宽的信息
		*/
		void setMaxSize(float width, float height);
		/**
		*	设置最大长宽的信息
		*/
		void setMaxSize(const math::Size& size);
		/**
		*	获取在窗体大小改变时的自我调整策略
		*/
		SizePolicy& getSizePolicy();
		/**
		*	获取在窗体大小改变时的自我调整策略
		*/
		void setSizePolicy(const SizePolicy& policy);
	public: // 可能需重载的方法
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
		virtual bool copy(LayoutItemEx* item);
	protected:
		// 最小面积
		math::Size m_sMinSize;
		// 最大面积
		math::Size m_sMaxSize;
		// 大小调整策略
		SizePolicy m_spAdjust;
	};
}