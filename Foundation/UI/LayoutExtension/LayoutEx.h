#pragma once

#include "LayoutItemEx.h"
#include "macros.h"

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
		bool copy(LayoutEx* item);
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
		// ��Ԫ������
		std::vector<LayoutItemEx*> _items;
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