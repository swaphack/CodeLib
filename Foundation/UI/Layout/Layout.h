#pragma once

#include "system.h"

#include "LayoutItem.h"

namespace ui
{
	// ��СԼ��
	enum SizeConstraint
	{
		// �̶���С
		ESC_FixedSize,
		// ��С����Сʱ������С
		ESC_MinimumSize,
		// �Ŵ�����Ǳ������
		ESC_MaximumSize,
		// �Զ�����
		ESC_Expending,
	};

	/**
	*	���沼��
	*	���в����е����Ϊˮƽ����
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
	public:
		/**
		*	�����ڴ�С�����ı�ʱ
		*/
		virtual void onViewSizeChanged(const sys::Size& inputSize);
		/**
		*	��ȡ���ֵ���С���
		*/
		virtual sys::Size getLayoutItemMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual sys::Size getLayoutItemMaxSize();
	protected:
		/**
		*	��ȡ�����ڲ�����С���
		*/
		virtual sys::Size getLayoutInnerMinSize() = 0;
		/**
		*	��ȡ�����ڲ���������
		*/
		virtual sys::Size getLayoutInnerMaxSize() = 0;
		/**
		*	�����ڲ���С�ı�
		*	�����̶���С�Ͱٷֱ��������
		*	�ȼ���̶���С��ֵ���ټ���ٷֱȵ�ֵ
		*/
		virtual void onLayoutInnerSizeChanged(const sys::Size& innerSize) = 0;
		/**
		*	���㲼������
		*/
		virtual float calItemWidth(LayoutItem* item, float width);
		/**
		*	���㲼������
		*/
		virtual float calItemHeight(LayoutItem* item, float height);
	protected:
		// ���Ե����
		float m_fLeftMargin;
		// �ұ�Ե����
		float m_fRightMargin;
		// �ϱ�Ե����
		float m_fTopMargin;
		// �±�Ե����
		float m_fBottomMargin;
		// ��Ԫ������
		std::vector<LayoutItem*> m_vChildren;		
	};

	/**
	*	ˮƽ����, �����Ҽ�������
	*/
	class HorizontalLayout : public Layout
	{
	public:
		HorizontalLayout();
		virtual ~HorizontalLayout();
	public:
		/**
		*	��ȡ�����ڲ�����С���
		*/
		virtual sys::Size getLayoutInnerMinSize();
		/**
		*	��ȡ�����ڲ���������
		*/
		virtual sys::Size getLayoutInnerMaxSize();
		/**
		*	�����ڲ���С�ı�
		*	 
		*/
		virtual void onLayoutInnerSizeChanged(const sys::Size& innerSize);
	};

	/** 
	*	��ֱ����, ���µ��ϼ�������
	*/
	class VerticalLayout : public Layout
	{
	public:
		VerticalLayout();
		virtual ~VerticalLayout();
	public:
		/**
		*	��ȡ���ֵ���С���
		*/
		virtual sys::Size getLayoutItemMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual sys::Size getLayoutItemMaxSize();
	protected:
		// �����ڴ�С�����ı�ʱ
		virtual void onLayoutInnerSizeChanged(const sys::Size& innerSize);
	};

	// ���Ӳ���
	class GridLayout : public Layout
	{
	public:
		GridLayout();
		virtual ~GridLayout();
	public:
		// �����ڴ�С�����ı�ʱ
		virtual void onLayoutInnerSizeChanged(const sys::Size& innerSize);
	};
}