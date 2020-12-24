#pragma once

#include "system.h"
#include "render.h"

namespace ui
{
	class CtrlWidget;

	class LayoutItemBase : 
		public sys::Object, 
		public sys::Name
	{
	public:
		LayoutItemBase();
		virtual ~LayoutItemBase();
	public:
		/**
		*	设置控件名称
		*/
		void setWidgetName(const std::string& name);
		/**
		*	获取控件名称
		*/
		const std::string& getWidgetName() const;
		/**
		*	设置元件
		*/
		void setWidget(CtrlWidget* widget);
		/**
		*	获取元件
		*/
		CtrlWidget* getWidget() const;
		/**
		*	获取元件
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<CtrlWidget, T>::value, T>::type>
		T* getCastWidget() const
		{
			if (getWidget() == nullptr)
			{
				return nullptr;
			}
			return getWidget()->as<T>();
		}
	public: 
		/**
		*	自动调整大小
		*/
		void autoResize();
		/**
		*	复制对象
		*/
		bool copy(LayoutItemBase* item);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const math::Size& size);
	public:
		/**
		*	刷新
		*/
		void refresh();
	protected:
		// 空置项
		CtrlWidget* m_pWidget = nullptr;
		// 控件名称
		std::string m_strWidgetName;
		// 父节点大小
		math::Size m_sParentSize;
	};
}