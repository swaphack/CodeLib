#pragma once

#include "Panel.h"

namespace ue
{
	/**
	*	单独面板
	*/
	class SinglePanel : public Panel
	{
	public:
		SinglePanel();
		virtual ~SinglePanel();

	public:
		virtual bool init();
	public:
		/**
		*	面板配置路径
		*/
		virtual const char* getPanelPath();
		/**
		*	更新位置
		*/
		void updatePosition(const ui::CtrlWidget* item, sys::CSSDirection eDir);
	public:
		/**
		*	显示
		*/
		void show();
		/**
		*	显示
		*/
		void showWithTarget(const ui::CtrlWidget* item, sys::CSSDirection eDir);
		/**
		*	关闭
		*/
		void close();
	protected:
		/**
		*	设置主体位置
		*/
		void setPositionLeftTop(const math::Vector2& pos);
		/**
		*	设置主体位置
		*/
		void setPositionRightTop(const math::Vector2& pos);
		/**
		*	设置主体位置
		*/
		void setPositionLeftBottom(const math::Vector2& pos);
		/**
		*	设置主体位置
		*/
		void setPositionRightBottom(const math::Vector2& pos);
	protected:
		// 主体
		ui::CtrlWidget* _body = nullptr;
	};
}