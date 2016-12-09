#pragma once

#include "macros.h"

namespace ui
{
	/**
	*	ui基本元件 与其他控件转嫁的中间者
	*	几何信息：以左下角为原点，定义指定长宽的矩形
	*
	*/ 
	class Widget : public sys::Object
	{
	public:
		Widget();
		virtual ~Widget();
	public:
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
		*	设置几何面积
		*/
		void setSize(float width, float height);
		/**
		*	获取最小长宽的信息
		*/
		const sys::Size& getMinSize();
		/**
		*	设置最小长宽的信息
		*/
		void setMinSize(float width, float height);
		/**
		*	获取最大长宽的信息
		*/
		const sys::Size& getMaxSize();
		/**
		*	设置最大长宽的信息
		*/
		void setMaxSize(float width, float height);
	protected:
		// 几何信息
		sys::Rect m_rGeometry;
		// 最小面积
		sys::Size m_sMinSize;
		// 最大面积
		sys::Size m_sMaxSize;
		// 矩形框颜色
		sys::Color4B _rectColor;
		// 是否显示矩形框
		bool _bBoxVisible;
	};
}