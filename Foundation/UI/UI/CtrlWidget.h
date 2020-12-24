#pragma once

#include "render.h"
#include "AutoResizeProtocol.h"

namespace ui
{
	class LayoutItem;

	/**
	*	UI控件基类
	*/
	class CtrlWidget : 
		public render::DrawNode2D,
		public render::TouchProtocol
	{
	public:
		// 点击处理函数
		typedef std::function<void(CtrlWidget*)> ClickWidgetFunc;
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
		/**
		*	根据名字查找控件
		*/
		CtrlWidget* findWidgetByName(const std::string& name);
		/**
		*	根据名字查找控件
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<CtrlWidget, T>::value, T>::type>
		bool findWidgetByName(const std::string& name, T* &target)
		{
			auto pWidget = findWidgetByName(name);
			if (pWidget == nullptr)
			{
				return false;
			}

			target = pWidget->as<T>();

			return target != nullptr;
		}
		/**
		*	获取所有控件
		*/
		const std::vector<CtrlWidget*>& getAllWidgets() const;
		/**
		*	获取第一个子节点
		*/
		CtrlWidget* getFirstWidget() const;
		/**
		*	从父节点移除
		*/
		virtual void removeFromParent();
	public:
		/**
		*	布局信息
		*/
		void setLayoutItem(LayoutItem* item);
		/**
		*	重置布局信息
		*/
		void resetLayoutItem();
		/**
		*	布局信息
		*/
		LayoutItem* getLayoutItem();
		/**
		*	布局信息
		*/
		void resize(const math::Size& size);
	public:
		/**
		*	是否可点击
		*/
		bool isTouchEnable();
		/**
		*	设置是否可点击
		*/
		void setTouchEnable(bool bEnabled);
		/**
		*	添加点击事件
		*/
		void addClickFunc(const ClickWidgetFunc& func);
		/**
		*	移除所有点击事件
		*/
		void removeAllClickFuncs();
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
		*	形状改变
		*/
		void onCtrlWidgetBodyChange();
	public:
		/**
		*	通知子节点形状改变
		*/
		void broadcastBodyChange();
		/**
		*	刷新布局
		*/
		void refreshLayout();
	protected:
		/**
		*	父节点节点形状改变
		*/
		void onParentBodyChange();
	protected:
		/**
		*	添加内部访问控件
		*/
		void addProtectedWidget(CtrlWidget* widget);
		/**
		*	移除内部访问控件
		*/
		void removeProtectedWidget(CtrlWidget* widget);
		/**
		*	移除所有内部访问控件
		*/
		void removeAllProtectedWidgets();
	protected:
		// 内部访问控件
		std::vector<CtrlWidget*> _protectedWidgets;
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
		/**
		*	点击事件
		*/
		std::vector<ClickWidgetFunc> _clickFuncs;
		/**
		*	布局信息
		*/
		LayoutItem* _layoutItem = nullptr;
	};
}