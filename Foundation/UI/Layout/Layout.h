#pragma once

#include "LayoutItem.h"

namespace ui
{
	/**
	*	���沼��
	*	����С�ı�ʱ�������ڲ��ṹ�����ڲ��ṹ�ﵽ�ٽ�ֵʱ������С���ܸı�
	*	�������е�Ԫ�����������С�����ı�ʱ������Ԫ����λ�úʹ�С
	*/
	class Layout : public LayoutItem
	{
	public:
		Layout();
		virtual ~Layout();
	public:
		/**
		*	���һ��Ԫ��
		*/
		void addItem(LayoutItem* item);
		/**
		*	�Ƴ�һ��Ԫ��
		*/
		void removeItem(LayoutItem* item);
		/**
		*	�Ƴ�����Ԫ��
		*/
		void removeAllItems();
		/**
		*	��ȡ��Ԫ��
		*/
		const std::vector<LayoutItem*>& getAllItems() const;
		/**
		*	������Ԫ��
		*/
		LayoutItem* findItemByName(const std::string& name) const;

		template<typename T, typename = std::enable_if<std::is_base_of<LayoutItem, T>::value, T>::type>
		bool findItemByName(const std::string& name, T* & t) const
		{
			LayoutItem* pItem = findItemByName(name);
			if (pItem == nullptr) return false;

			t = pItem->as<T>();

			return t != nullptr;
		}
		/**
		*	������Ԫ���ؼ�
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<render::CtrlWidget, T>::value, T>::type>
		bool findWidgetByName(const std::string& name, T* & t) const
		{
			LayoutItem* pItem = findItemByName(name);
			if (pItem == nullptr) return false;

			t = pItem->getWidget<T>();

			return t != nullptr;
		}
		/**
		*	������Ԫ��
		*/
		LayoutItem* getItem(int index) const;
	public:
		/**
		*	�����ڴ�С�����ı�ʱ
		*/
		virtual void resize(const math::Size& size);
		/**
		*	���ƶ���
		*/
		bool copy(Layout* item);
	protected:
		/**
		*	�����ڲ���С�ı�
		*	�����̶���С�Ͱٷֱ��������
		*	�ȼ���̶���С��ֵ���ټ���ٷֱȵ�ֵ
		*/
		virtual void onLayoutSizeChanged(const math::Size& innerSize);		
	protected:
		// ��Ԫ������
		std::vector<LayoutItem*> _items;		
	};
}