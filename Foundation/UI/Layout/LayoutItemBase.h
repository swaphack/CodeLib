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
		/**
		*	获取元件
		*/
		template<typename T>
		T* getWidget() const
		{
			if (getWidget() == nullptr)
			{
				return nullptr;
			}
			return getWidget()->as<T>();
		}
		/**
		*	设置盒子是否可见
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	是否包含点
		*/
		bool containPoint(float x, float y);
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
	};
}