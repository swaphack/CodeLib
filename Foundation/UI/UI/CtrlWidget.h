#pragma once

#include "render.h"
#include "AutoResizeProtocol.h"

namespace render
{
	class ShaderProgram;
}

namespace ui
{
	class LayoutItem;

	/**
	*	UI控件基类
	*/
	class CtrlWidget : 
		public render::Node,
		public render::Box2DDrawProtocol
	{
	public:
		// 点击处理函数
		typedef std::function<void(CtrlWidget*)> ClickWidgetFunc;
	public:
		CtrlWidget();
		virtual ~CtrlWidget();
	public:
		virtual bool init();
		/**
		*	设置着色器
		*/
		virtual void setTexShaderProgram(render::ShaderProgram* shaderProgram);
		/**
		*	设置着色器
		*/
		virtual void setColorShaderProgram(render::ShaderProgram* shaderProgram);
	public:
		/**
		*	坐标是否在当前对象内
		*/
		virtual bool containPoint(const math::Vector2& touchPoint);
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
		template<typename T, typename = std::enable_if<std::is_base_of<ui::CtrlWidget, T>::value, T>::type>
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
		/**
		*	获取控件个数
		*/
		int getWidgetCount() const;
		/**
		*	按照索引获取控件
		*/
		CtrlWidget* getWidgetByIndex(int index) const;
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
		LayoutItem* getLayoutItem() const;
		/**
		*	布局信息
		*/
		void resize(const math::Size& size);
	public:
		/**
		*	添加点击事件
		*/
		void addClickFunc(const ClickWidgetFunc& func);
		/**
		*	移除所有点击事件
		*/
		void removeAllClickFuncs();
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
		/**
		*	裁剪数量
		*/
		static int s_nScissorCount;
	};
}