#pragma once

#include "CtrlScrollView.h"

namespace render
{
	// ��������
	enum class ScrollDirection
	{
		// ˮƽ��������
		HORIZONTAL_LEFT_TO_RIGHT,
		// ˮƽ��������
		HORIZONTAL_RIGHT_TO_LEFT,
		// ˮƽ��������
		VERTICAL_TOP_TO_BOTTOM,
		// ˮƽ��������
		VERTICAL_BOTTOM_TO_TOP,
	};

	// �б�
	class CtrlListView : public CtrlScrollView
	{
	public:
		CtrlListView();
		virtual ~CtrlListView();
	public:
		virtual bool init();
	public:
		/**
		*	���û�������
		*/
		void setScrollDirection(ScrollDirection direction);
		/**
		*	��ȡ��������
		*/
		ScrollDirection getScrollDirection();
		/**
		*	������Ĵ�С
		*/
		void setItemSize(const math::Size& size);
		/**
		*	������Ĵ�С
		*/
		void setItemSize(float width, float height);
		/**
		*	��ȡ������Ĵ�С
		*/
		const math::Size& getItemSize();
	public:
		/**
		*	���һ����
		*/
		virtual void addItem(CtrlWidget* item, int zOrder = 0);
	protected:
		virtual bool onTouchMoved(float x, float y, bool include);
	protected:
		// ��ʼ��������
		virtual void initItems();
		// ��ʼ��������
		virtual void initContent();
	protected:
		// ��������
		ScrollDirection _scrollDirection = ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT;
		// ��Ĵ�С
		math::Size _itemSize;
	};
}
