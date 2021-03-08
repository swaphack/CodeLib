#pragma once

#include "render.h"
#include "AutoResizeProtocol.h"

namespace ui
{
	class LayoutItem;

	/**
	*	UI�ؼ�����
	*/
	class CtrlWidget : 
		public render::DrawNode2D
	{
	public:
		// ���������
		typedef std::function<void(CtrlWidget*)> ClickWidgetFunc;
	public:
		CtrlWidget();
		virtual ~CtrlWidget();
	public:
		virtual bool init();
	public:
		/**
		*	��ӿؼ�
		*/
		virtual void addWidget(CtrlWidget* widget);
		/**
		*	��ӿؼ�
		*/
		virtual void addWidget(CtrlWidget* widget, int zOrder);
		/**
		*	�Ƴ��ؼ�
		*/
		virtual void removeWidget(CtrlWidget* widget);
		/**
		*	�Ƴ����пؼ�
		*/
		virtual void removeAllWidgets();
		/**
		*	�������ֲ��ҿؼ�
		*/
		CtrlWidget* findWidgetByName(const std::string& name);
		/**
		*	�������ֲ��ҿؼ�
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
		*	��ȡ���пؼ�
		*/
		const std::vector<CtrlWidget*>& getAllWidgets() const;
		/**
		*	��ȡ��һ���ӽڵ�
		*/
		CtrlWidget* getFirstWidget() const;
		/**
		*	�Ӹ��ڵ��Ƴ�
		*/
		virtual void removeFromParent();
		/**
		*	��ȡ�ؼ�����
		*/
		int getWidgetCount() const;
		/**
		*	����������ȡ�ؼ�
		*/
		CtrlWidget* getWidgetByIndex(int index) const;
	public:
		/**
		*	������Ϣ
		*/
		void setLayoutItem(LayoutItem* item);
		/**
		*	���ò�����Ϣ
		*/
		void resetLayoutItem();
		/**
		*	������Ϣ
		*/
		LayoutItem* getLayoutItem() const;
		/**
		*	������Ϣ
		*/
		void resize(const math::Size& size);
	public:
		/**
		*	��ӵ���¼�
		*/
		void addClickFunc(const ClickWidgetFunc& func);
		/**
		*	�Ƴ����е���¼�
		*/
		void removeAllClickFuncs();
	protected:
		virtual void beforeDrawNode();
		/**
		*	����
		*/
		virtual void afterDrawNode();
	protected:
		/**
		*	��״�ı�
		*/
		void onCtrlWidgetBodyChange();
	public:
		/**
		*	֪ͨ�ӽڵ���״�ı�
		*/
		void broadcastBodyChange();
		/**
		*	ˢ�²���
		*/
		void refreshLayout();
	protected:
		/**
		*	���ڵ�ڵ���״�ı�
		*/
		void onParentBodyChange();
	protected:
		/**
		*	����ڲ����ʿؼ�
		*/
		void addProtectedWidget(CtrlWidget* widget);
		/**
		*	�Ƴ��ڲ����ʿؼ�
		*/
		void removeProtectedWidget(CtrlWidget* widget);
		/**
		*	�Ƴ������ڲ����ʿؼ�
		*/
		void removeAllProtectedWidgets();
	protected:
		// �ڲ����ʿؼ�
		std::vector<CtrlWidget*> _protectedWidgets;
		// �ؼ�
		std::vector<CtrlWidget*> _widgets;
		/**
		*	�ü�����
		*/
		math::Rect _clipRect;
		/**
		*	����¼�
		*/
		std::vector<ClickWidgetFunc> _clickFuncs;
		/**
		*	������Ϣ
		*/
		LayoutItem* _layoutItem = nullptr;
	};
}