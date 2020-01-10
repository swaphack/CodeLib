#pragma once

#include "LayoutItemEx.h"

namespace ui
{
	/**
	*	���沼��
	*	����С�ı�ʱ�������ڲ��ṹ�����ڲ��ṹ�ﵽ�ٽ�ֵʱ������С���ܸı�
	*	�������е�Ԫ�����������С�����ı�ʱ������Ԫ����λ�úʹ�С
	*/
	class LayoutEx : public LayoutItemEx
	{
	public:
		LayoutEx();
		virtual ~LayoutEx();
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
		void addItem(LayoutItemEx* item);
		/**
		*	�Ƴ�һ��Ԫ��
		*/
		void removeItem(LayoutItemEx* item);
		/**
		*	�Ƴ�����Ԫ��
		*/
		void removeAllItems();
		/**
		*	��ȡ��Ԫ��Ԫ��
		*/
		const std::vector<LayoutItemEx*>& getChildren();
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
		*	��ȡ���ֵ���С���
		*/
		virtual math::Size getLayoutMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual math::Size getLayoutMaxSize();
		/**
		*	���ƶ���
		*/
		virtual bool copy(LayoutEx* item);
	protected:
		/**
		*	��ȡ�����ڲ�����С���
		*/
		virtual math::Size getLayoutInnerMinSize();
		/**
		*	��ȡ�����ڲ���������
		*/
		virtual math::Size getLayoutInnerMaxSize();
		/**
		*	�����ڲ���С�ı�
		*	�����̶���С�Ͱٷֱ��������
		*	�ȼ���̶���С��ֵ���ټ���ٷֱȵ�ֵ
		*/
		virtual void onLayoutSizeChanged(const math::Size& innerSize);
		/**
		*	���㲼������
		*/
		virtual float calItemWidth(LayoutItemEx* item, float width);
		/**
		*	���㲼������
		*/
		virtual float calItemHeight(LayoutItemEx* item, float height);
	protected:
		// ��Ե����
		sys::Margin m_fMargin;
		// ��Ԫ������
		std::vector<LayoutItemEx*> m_vChildren;
	};

	/**
	*	ˮƽ����, �����Ҽ�������
	*/
	class HorizontalLayout : public LayoutEx
	{
	public:
		HorizontalLayout();
		virtual ~HorizontalLayout();
	public:
		/**
		*	��ȡ�����ڲ�����С���
		*/
		virtual math::Size getLayoutInnerMinSize();
		/**
		*	��ȡ�����ڲ���������
		*/
		virtual math::Size getLayoutInnerMaxSize();
	};

	/** 
	*	��ֱ����, ���µ��ϼ�������
	*/
	class VerticalLayout : public LayoutEx
	{
	public:
		VerticalLayout();
		virtual ~VerticalLayout();
	public:
		/**
		*	��ȡ���ֵ���С���
		*/
		virtual math::Size getLayoutInnerMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual math::Size getLayoutInnerMaxSize();
	};

	// ���Ӳ���
	class GridLayout : public LayoutEx
	{
	public:
		GridLayout();
		virtual ~GridLayout();
	public:
		/**
		*	��ȡ���ֵ���С���
		*/
		virtual math::Size getLayoutInnerMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual math::Size getLayoutInnerMaxSize();
	};
}