#pragma once

#include "macros.h"
#include "ui_common.h"

namespace ui
{
	class Layout;
	/**
	*	布局项, 抽象类
	*	布局项的集合信息在界面调整中不做改变，改变的只有CtrlWidget的集合信息
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
		const math::Rect& getGeometry();
		/**
		*	设置几何信息
		*/
		void setGeometry(const math::Rect& rect);
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
		void setOrgin(const math::Vector2& position);
		/**
		*	获取几何位置
		*/
		math::Vector2 getOrgin();
		/**
		*	设置几何面积
		*/
		void setSize(float width, float height);
		/**
		*	设置几何面积
		*/
		void setSize(const math::Size& size);
		/**
		*	获取几何面积
		*/
		math::Size getSize();
		/**
		*	设置元件
		*/
		void setWidget(render::CtrlWidget* widget);
		/**
		*	获取元件
		*/
		render::CtrlWidget* getWidget();
		/**
		*	设置锚点位置
		*/
		void setAnchorPoint(const math::Vector2& anchorPoint);
		/**
		*	获取锚点位置
		*/
		const math::Vector2& getAnchorPoint() const;
	public: // 可能需重载的方法
		/**
		*	复制对象
		*/
		bool copy(LayoutItem* item);
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const math::Rect& rect);
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
		void setWidgetGeomerty(const math::Rect& geometry, const math::Vector2& anchorPoint);
	public:
		void showWidgetInfo();
	protected:
		void calAnchorPoint(float& x, float& y);
	protected:
		// 几何信息
		math::Rect m_rGeometry;
		// 锚点位置
		math::Vector2 m_vAnchorPoint;
		// 矩形框颜色
		sys::Color4B m_cBoxColor;
		// 是否显示矩形框
		bool m_bBoxVisible = false;
		// 空置项
		render::CtrlWidget* m_pWidget = nullptr;
	};
}