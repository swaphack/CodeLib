#pragma once

#include "macros.h"

#include "SizePolicy.h"

namespace ui
{
	class Layout;

	/**
	*	布局项
	*	布局项的集合信息在界面调整中不做改变，改变的只有widget的集合信息
	*/
	class LayoutItem : public sys::Object
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
		void setPosition(float x, float y);
		/**
		*	设置几何位置
		*/
		void setPosition(const sys::Point& position);
		/**
		*	获取几何位置
		*/
		sys::Point getPosition();
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
		*	获取最小长宽的信息
		*/
		const sys::Size& getMinSize();
		/**
		*	设置最小长宽的信息
		*/
		void setMinSize(float width, float height);
		/**
		*	设置最小长宽的信息
		*/
		void setMinSize(const sys::Size& size);
		/**
		*	获取最大长宽的信息
		*/
		const sys::Size& getMaxSize();
		/**
		*	设置最大长宽的信息
		*/
		void setMaxSize(float width, float height);
		/**
		*	设置最大长宽的信息
		*/
		void setMaxSize(float width, float height);
		/**
		*	设置元件
		*/
		void setWidget(Widget* widget);
		/**
		*	获取元件
		*/
		Widget* getWidget();
		/**
		*	设置布局
		*/
		void setLayout(Layout* layout);
		/**
		*	获取布局
		*/
		Layout* getLayout();
		/**
		*	获取在窗体大小改变时的自我调整策略
		*/
		SizePolicy& getSizePolicy();
	public: // 可能需重载的方法
		/**
		*	设置布局项的几何信息
		*/
		virtual void setLayoutItemGeometry(const sys::Rect& rect);
		/**
		*	获取布局的最小面积
		*/
		virtual sys::Size getLayoutItemMinSize();
		/**
		*	获取布局的最大面积
		*/
		virtual sys::Size getLayoutItemMaxSize();
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
		// 最小面积
		sys::Size m_sMinSize;
		// 最大面积
		sys::Size m_sMaxSize;
		// 矩形框颜色
		sys::Color4B m_rectColor;
		// 是否显示矩形框
		bool m_bBoxVisible;
		// 空置项
		Widget* m_pWidget;
		// 布局
		Layout* m_pLayout;
		// 大小调整策略
		SizePolicy m_spAdjust;
	};

	// 方向
	enum Orientation
	{
		// 水平
		EO_Horizontal,
		// 垂直
		EO_Vertial,
	};

	/**
	*	空置项，用于填充
	*/
	class LayoutSpacerItem : public LayoutItem
	{
	public:
		LayoutSpacerItem();
		virtual ~LayoutSpacerItem();
	public:
		/**
		*	设置空置项方向
		*/
		void setOrientation(Orientation eType);
		/**
		*	获取空置项方向
		*/
		Orientation getOrientation();
	protected:
		// 空置项方向
		Orientation m_eOrientation;
	};

	/**
	*	元件项，用于元件在界面位置和大小设定
	*/
	class LayoutWidgetItem : public LayoutItem
	{
	public:
		LayoutWidgetItem(Widget* widget);
		virtual ~LayoutWidgetItem();
	public:
	};
}