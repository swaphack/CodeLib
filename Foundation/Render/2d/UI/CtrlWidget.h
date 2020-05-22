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
		public ColorProtocol,
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
	protected:
		virtual void beforeDrawNode();
		virtual void afterDrawNode();
	public:
		/**
		*	坐标是否在当前对象内
		*/
		const RectVectices& getRectVertex();
		/**
		*	坐标是否在当前对象内
		*/
		virtual bool containTouchPoint(float x, float y);
	protected:
		void calRectData();
	protected:
		virtual void onColorChange();
		virtual void onBlendChange();
	protected:
		// 矩形框
		RectVectices _rectVertex;
		// 实际矩形框
		RectVectices _realRectVertex;
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