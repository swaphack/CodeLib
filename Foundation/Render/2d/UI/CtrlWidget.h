#pragma once

#include "Common/DrawNode/import.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class Materials;

	/**
	*	UI控件基类
	*/
	class CtrlWidget : public DrawNode,
		public BlendProtocol
	{
	public:
		CtrlWidget();
		virtual ~CtrlWidget();
	public:
		virtual bool init();
	public:
		/**
		*	添加控件
		*/
		void addWidget(CtrlWidget* widget);
		/**
		*	添加控件
		*/
		void addWidget(CtrlWidget* widget, int zOrder);
		/**
		*	移除控件
		*/
		void removeWidget(CtrlWidget* widget);
		/**
		*	移除所有控件
		*/
		void removeAllWidgets();
	public:
		/**
		*	是否裁剪
		*/
		void setClip(bool bClip);
		/**
		*	是否裁剪
		*/
		bool isClip();
		/**
		*	是否显示矩形框
		*/
		void setRectVisible(bool bVisible);
		/**
		*	是否显示矩形框
		*/
		bool isRectVisible();
	protected:
		virtual void beforeDrawNode();
		/**
		*	绘制
		*/
		virtual void afterDrawNode();
	public:
		/**
		*	获取矩形框
		*/
		const RectVectices& getRectVertex();
		/**
		*	坐标是否在当前对象内
		*/
		virtual bool containTouchPoint(float x, float y);
	protected:
		void calRectData();
	protected:
		/**
		*	混合改变
		*/
		virtual void onBlendChange();
		/**
		*	绘制矩形
		*/
		void drawRect();
	protected:
		/**
		*	是否显示矩形框
		*/
		bool _bRectVisible = false;
		// 矩形框
		RectVectices _rectVertex;
		// 实际矩形框
		RectVectices _realRectVertex;
		// 实际多边形
		math::Polygon<4> _realPolygon;
		// 控件
		std::vector<CtrlWidget*> _widgets;
		/**
		*	是否裁剪
		*/
		bool _bClip = false;
		/**
		*	裁剪区域
		*/
		math::Rect _clipRect;
	};
}