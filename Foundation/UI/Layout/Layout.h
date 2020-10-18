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
		const std::vector<LayoutItem*>& getChildren() const;
		/**
		*	������Ԫ��
		*/
		LayoutItem* findItemByName(const std::string& name) const;
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
		std::vector<LayoutItem*> m_vChildren;		
	};
}