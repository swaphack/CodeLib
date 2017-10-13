#pragma once

#include "macros.h"

namespace ui
{
	class LayoutEx;
	/**
	*	布局项, 抽象类
	*	布局项的集合信息在界面调整中不做改变，改变的只有widget的集合信息
	*/
	class LayoutItem : public sys::Object, public sys::Name
	{
	public:
		LayoutItem();
		virtual ~LayoutItem();
	public: // 固定不变的数据
		/**
		*	几何信息
		*/
		const sys::Rect& getGeometry();
		/**
		*	设置几何信息
		*/
		void setGeometry(const sys::Rect& rect);
		/**
		*	设置几何信息
		*/
		void setGeometry(float x, float y, float width, float height);
		/**
		*	设置几何位置
		*/
		void setOrgin(float x, float y);
		/**
		*	设置几何位置
		*/
		void setOrgin(const sys::Vector2& position);
		/**
		*	获取几何位置
		*/
		sys::Vector2 getOrgin();
		/**
		*	设置几何面积
		*/
		void setSize(float width, float height);
		/**
		*	设置几何面积
		*/
		void setSize(const sys::Size& size);
		/**
		*	获取几何面积
		*/
		sys::Size getSize();
		/**
		*	设置元件
		*/
		void setWidget(Widget* widget);
		/**
		*	获取元件
		*/
		Widget* getWidget();
	public: // 可能需重载的方法
		/**
		*	复制对象
		*/
		bool copy(LayoutItem* item);
	public: // 其他辅助方法
		/**
		*	设置矩形框是否可见
		*/
		void setBoxVisible(bool status);
		/**
		*	矩形框是否可见
		*/
		bool isBoxVisible();
		/**
		*	设置矩形框显示颜色
		*/
		void setBoxColor(const sys::Color4B& color);
		/**
		*	获取矩形框显示颜色
		*/
		const sys::Color4B& getBoxColor();
		/**
		*	设置元件的集合信息
		*/
		void setWidgetGeomerty(const sys::Rect& geometry);
	protected:
		// 几何信息
		sys::Rect m_rGeometry;
		// 矩形框颜色
		sys::Color4B m_cBoxColor;
		// 是否显示矩形框
		bool m_bBoxVisible;
		// 空置项
		Widget* m_pWidget;
	};
}