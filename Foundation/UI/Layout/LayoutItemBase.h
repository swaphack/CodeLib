#pragma once

#include "system.h"
#include "render.h"

namespace ui
{
	class CtrlWidget;

	class LayoutItemBase : 
		public sys::Object, 
		public sys::Name
	{
	public:
		LayoutItemBase();
		virtual ~LayoutItemBase();
	public:
		/**
		*	���ÿؼ�����
		*/
		void setWidgetName(const std::string& name);
		/**
		*	��ȡ�ؼ�����
		*/
		const std::string& getWidgetName() const;
		/**
		*	����Ԫ��
		*/
		void setWidget(CtrlWidget* widget);
		/**
		*	��ȡԪ��
		*/
		CtrlWidget* getWidget() const;
		/**
		*	��ȡԪ��
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<CtrlWidget, T>::value, T>::type>
		T* getCastWidget() const
		{
			if (getWidget() == nullptr)
			{
				return nullptr;
			}
			return getWidget()->as<T>();
		}
	public: 
		/**
		*	�Զ�������С
		*/
		void autoResize();
		/**
		*	���ƶ���
		*/
		bool copy(LayoutItemBase* item);
		/**
		*	������λ�úʹ�С�����ı�ʱ
		*/
		virtual void resize(const math::Size& size);
	public:
		/**
		*	ˢ��
		*/
		void refresh();
	protected:
		// ������
		CtrlWidget* m_pWidget = nullptr;
		// �ؼ�����
		std::string m_strWidgetName;
		// ���ڵ��С
		math::Size m_sParentSize;
	};
}