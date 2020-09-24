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
		*	�������Ե����
		*/
		void setLeftMargin(float margin);
		/**
		*	��ȡ���Ե����
		*/
		float getLeftMargin();
		/**
		*	�����ұ�Ե����
		*/
		void setRightMargin(float margin);
		/**
		*	��ȡ�ұ�Ե����
		*/
		float getRightMargin();
		/**
		*	�����ϱ�Ե����
		*/
		void setTopMargin(float margin);
		/**
		*	��ȡ�ϱ�Ե����
		*/
		float getTopMargin();
		/**
		*	�����±�Ե����
		*/
		void setBottomMargin(float margin);
		/**
		*	��ȡ���Ե����
		*/
		float getBottomMargin();
		/**
		*	���ñ�Ե����
		*/
		void setMargin(const sys::Margin& margin);
		/**
		*	��ȡ��Ե����
		*/
		const sys::Margin& getMargin();
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
		*	��ȡ��Ԫ��Ԫ��
		*/
		const std::vector<LayoutItem*>& getChildren();
	public:
		/**
		*	�����ڴ�С�����ı�ʱ
		*/
		virtual void resize(const math::Size& size);
		/**
		*	������λ�úʹ�С�����ı�ʱ
		*/
		virtual void resize(const math::Vector2& position, const math::Size& size);
		/**
		*	������λ�úʹ�С�����ı�ʱ
		*/
		virtual void resize(const math::Rect& rect);
		/**
		*	���ƶ���
		*/
		bool copy(Layout* item);
		/**
		*	�����ڲ���С�ı�
		*	����λ��
		*/
		static void calLayoutSpace(LayoutItem* child, const math::Size& srcSize, const math::Size& newSize, math::Vector2& point, math::Size& size);
	protected:
		/**
		*	�����ڲ���С�ı�
		*	�����̶���С�Ͱٷֱ��������
		*	�ȼ���̶���С��ֵ���ټ���ٷֱȵ�ֵ
		*/
		virtual void onLayoutSizeChanged(const math::Size& innerSize);		
	protected:
		// ��Ե����
		sys::Margin m_fMargin;
		// ��Ԫ������
		std::vector<LayoutItem*> m_vChildren;		
	};
}