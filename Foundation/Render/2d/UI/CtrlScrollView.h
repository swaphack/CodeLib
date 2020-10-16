#pragma once

#include "CtrlWidget.h"
#include "CtrlLayout.h"
#include "Common/Input/TouchDelegate.h"

namespace render
{
	// ��������
	enum class ScrollDirection
	{
		NONE = -1,
		// ˮƽ��������
		HORIZONTAL_LEFT_TO_RIGHT,
		// ˮƽ��������
		HORIZONTAL_RIGHT_TO_LEFT,
		// ˮƽ��������
		VERTICAL_TOP_TO_BOTTOM,
		// ˮƽ��������
		VERTICAL_BOTTOM_TO_TOP,
	};

	class ScrollItem : public CtrlWidget
	{
	public:
		ScrollItem();
		virtual ~ScrollItem();
	public:
		// �����
		void addItem(Node* node, const math::Size& size);

	public:
		static ScrollItem* create(Node* node, const math::Size& size);
	};

	// ����
	class CtrlScrollView : public CtrlLayout
	{
	public:
		CtrlScrollView();
		virtual ~CtrlScrollView();
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
		*	���һ����
		*/  
		void addItem(CtrlWidget* item, int zOrder = 0);
		/**
		*	���һ����, �����ô�С
		*/
		void addItem(CtrlWidget* item, const math::Size& size, int zOrder = 0);
		/**
		*	�Ƴ�һ����
		*/ 
		void removeItem(CtrlWidget* item);
		/**
		*	�Ƴ�������
		*/ 
		void removeAllItems();
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
	public:// ��д
		virtual void addWidget(CtrlWidget* item);
		virtual void addWidget(CtrlWidget* item, int zOrder);
		virtual void removeWidget(CtrlWidget* item);
		virtual void removeAllWidgets();
	protected:
		// ��������
		virtual bool onTouchBegan(float x, float y, bool include);
		virtual bool onTouchMoved(float x, float y, bool include);
		virtual bool onTouchEnded(float x, float y, bool include);
	protected:
		// ��ʼ��������
		virtual void initItems();
		// ��ʼ��������
		virtual void initContent();
	protected:
		// ��������
		ScrollDirection _scrollDirection = ScrollDirection::HORIZONTAL_LEFT_TO_RIGHT;
		// �����������λ��
		CtrlLayout* _content = nullptr;
		// ��
		std::vector<CtrlWidget*> _itemWidgets;
		// ���λ��
		math::Vector2 _touchPosition;
		// ��Ĵ�С
		math::Size _itemSize;
	};
}