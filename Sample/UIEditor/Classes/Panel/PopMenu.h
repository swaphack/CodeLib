#pragma once

#include "Panel.h"

namespace ue
{
	/**
	*	弹出菜单
	*/
	class PopMenu : public Panel
	{
	public:
		PopMenu();
		virtual ~PopMenu();
	public:
		/**
		*	更新位置
		*/
		void updatePosition(const ui::LayoutItem* item, sys::CSSDirection eDir);
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
		/**
		*	初始化
		*/
		virtual void initUI();
		/**
		*	事件绑定
		*/
		virtual void initEvent();
		/**
		*	初始化文本
		*/
		virtual void initText();
	protected: // 点击
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
		*	显示
		*/
		static void show(const ui::LayoutItem* item, sys::CSSDirection eDir);
		/**
		*	显示
		*/
		static void show(const math::Vector2& pos = math::Vector2());
		/**
		*	隐藏
		*/
		static void hide();
		/**
		*	是否显示
		*/
		static bool isShow();
		/**
		*	实例
		*/
		static PopMenu* getInstance();
	private:
		// 弹窗
		static PopMenu* sPopMenu;
		// 主体
		ui::Layout* _body = nullptr;
	};
}
