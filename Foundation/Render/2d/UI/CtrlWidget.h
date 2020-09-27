#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class Materials;

	/**
	*	UI控件基类
	*/
	class CtrlWidget : public DrawNode2D,
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
	protected:
		virtual void beforeDrawNode();
		/**
		*	绘制
		*/
		virtual void afterDrawNode();
	protected:
		/**
		*	混合改变
		*/
		virtual void onBlendChange();
		/**
		*	形状改变
		*/
		void onCtrlWidgetBodyChange();
	protected:
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