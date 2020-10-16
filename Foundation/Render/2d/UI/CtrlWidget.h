#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Common/struct/shape_common.h"
#include "Common/Input/TouchDelegate.h"

namespace render
{
	class Materials;

	/**
	*	UI控件基类
	*/
	class CtrlWidget : 
		public DrawNode2D,
		public BlendProtocol,
		public TouchProtocol
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
		virtual void addWidget(CtrlWidget* widget);
		/**
		*	添加控件
		*/
		virtual void addWidget(CtrlWidget* widget, int zOrder);
		/**
		*	移除控件
		*/
		virtual void removeWidget(CtrlWidget* widget);
		/**
		*	移除所有控件
		*/
		virtual void removeAllWidgets();
	public:
		/**
		*	是否可点击
		*/
		bool isTouchEnable();
		/**
		*	设置是否可点击
		*/
		void setTouchEnable(bool bEnabled);
	protected:
		/**
		*	点击屏幕
		*/
		void onBeginTouch(Node* node, float x, float y, bool include);
		/**
		*	按住不松手
		*/
		void onMoveTouch(Node* node, float x, float y, bool include);
		/**
		*	放开
		*/
		void onEndTouch(Node* node, float x, float y, bool include);
	protected:
		/**
		*	点击屏幕
		*/
		virtual bool onTouchBegan(float x, float y, bool include);
		/**
		*	在屏幕上滑动
		*/
		virtual bool onTouchMoved(float x, float y, bool include);
		/**
		*	离开屏幕
		*/
		virtual bool onTouchEnded(float x, float y, bool include);
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