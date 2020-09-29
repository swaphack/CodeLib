#pragma once

#include "system.h"
#include "render.h"

namespace ui
{
	class LayoutItemBase : public sys::Object, public sys::Name
	{
	public:
		LayoutItemBase();
		virtual ~LayoutItemBase();
	public:
		/**
		*	设置元件
		*/
		void setWidget(render::CtrlWidget* widget);
		/**
		*	获取元件
		*/
		render::CtrlWidget* getWidget() const;
	public: // 其他辅助方法
	/**
	*	设置矩形框是否可见
	*/
		void setBoxVisible(bool status);
		/**
		*	矩形框是否可见
		*/
		bool isBoxVisible() const;
		/**
		*	设置矩形框显示颜色
		*/
		void setBoxColor(const sys::Color4B& color);
		/**
		*	获取矩形框显示颜色
		*/
		const sys::Color4B& getBoxColor() const;
	public: // 可能需重载的方法
		/**
		*	复制对象
		*/
		bool copy(LayoutItemBase* item);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const math::Size& size);
	protected:
		// 空置项
		render::CtrlWidget* m_pWidget = nullptr;
		// 矩形框颜色
		sys::Color4B m_cBoxColor;
		// 是否显示矩形框
		bool m_bBoxVisible = false;
	};
}