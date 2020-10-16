#pragma once

#include "Layout/LayoutItemBase.h"
#include "macros.h"

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
	class LayoutItemEx : public LayoutItemBase
	{
	public:
		LayoutItemEx();
		virtual ~LayoutItemEx();
	public: // 固定不变的数据
		/**
		*	获取最小长宽的信息
		*/
		const math::Size& getMinSize() const;
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
		const math::Size& getMaxSize() const;
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
		const SizePolicy& getSizePolicy() const;
		/**
		*	获取在窗体大小改变时的自我调整策略
		*/
		void setSizePolicy(const SizePolicy& policy);
	public:
		/**
		*	默认矩形框
		*/
		const math::Rect& getLayoutRect() const;
		/**
		*	默认矩形框
		*/
		void setLayoutRect(const math::Rect& rect);
		/**
		*	默认矩形框
		*/
		void setLayoutRect(const math::Vector2& position, const math::Size& size);
		/**
		*	默认大小
		*/
		const math::Size& getGeometry() const;
		/**
		*	默认位置
		*/
		const math::Vector2& getPosition() const;
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
		bool copy(LayoutItemEx* item);
	protected:
		// 矩形框
		math::Rect m_sDefaultRect;
		// 最小面积
		math::Size m_sMinSize;
		// 最大面积
		math::Size m_sMaxSize;
		// 大小调整策略
		SizePolicy m_spAdjust;
	};
}