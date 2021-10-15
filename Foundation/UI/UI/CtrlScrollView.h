#pragma once

#include "CtrlWidget.h"
#include "CtrlLayout.h"
#include "Common/Input/TouchDelegate.h"

namespace ui
{
	class CtrlScrollView;

	class ScrollItem : public CtrlWidget
	{
	public:
		ScrollItem();
		virtual ~ScrollItem();
	public:
		/**
		*	�����
		*/ 
		void addItem(CtrlWidget* node, const sys::CSSSize& size);
		/**
		*	���û�����ͼ
		*/
		void setScrollView(CtrlScrollView* view);
		/**
		*	���û�����ͼ
		*/
		const CtrlScrollView* getScrollView() const;
		/**
		*	��д�Ƴ�
		*/
		virtual void removeWidget(CtrlWidget* item);
	public:
		static ScrollItem* create(CtrlWidget* node, const sys::CSSSize& size, CtrlScrollView* view);
	private:
		/**
		*	���û�����ͼ
		*/
		CtrlScrollView* _relativeView = nullptr;
	};

	// ������ͼ
	class CtrlScrollView : public CtrlLayout
	{
	public:
		CtrlScrollView();
		virtual ~CtrlScrollView();
	public:
		virtual bool init();
	public:
		/**
		*	�����ڲ���С
		*/
		void setInnerSize(const math::Size& size);
		/**
		*	�ڲ���С
		*/
		math::Size getInnerSize();
		/**
		*	�ڲ�����
		*/
		const CtrlLayout* getInner() const;
	public:
		/**
		*	�ƶ�ϵ��
		*/
		void setMovingMultiple(float value);
		/**
		*	�ƶ�ϵ��
		*/
		float getMovingMultiple() const;
	public:
		/**
		*	���һ����
		*/  
		virtual void addItem(CtrlWidget* item, int zOrder = 0);
		/**
		*	���һ����, �����ô�С
		*/
		void addItem(CtrlWidget* item, const math::Size& size, int zOrder = 0);
		/**
		*	���һ����, �����ô�С
		*/
		void addItem(CtrlWidget* item, const sys::CSSSize& size, int zOrder = 0);
		/**
		*	�Ƴ�һ����
		*/ 
		void removeItem(CtrlWidget* item);
		/**
		*	�Ƴ�������
		*/ 
		void removeAllItems();
		/**
		*	��ȡ�ؼ�����
		*/
		int getItemCount() const;
		/**
		*	����������ȡ�ؼ�
		*/
		CtrlWidget* getItemByIndex(int index) const;
		/**
		*	����������ȡ�ؼ�
		*/
		CtrlWidget* findItemByName(const std::string& name) const;
	public:
		/**
		*	ˮƽ�����Ƿ���Ի���
		*/
		bool isHorizontalScroll() const;
		/**
		*	����ˮƽ�����Ƿ���Ի���
		*/
		void setHorizontalScroll(bool scroll);
		/**
		*	��ֱ�����Ƿ���Ի���
		*/
		bool isVerticalScroll() const;
		/**
		*	����ˮƽ�����Ƿ���Ի���
		*/
		void setVerticalScroll(bool scroll);
	public:// ��д
		virtual void addWidget(CtrlWidget* item);
		virtual void addWidget(CtrlWidget* item, int zOrder);
		virtual void removeWidget(CtrlWidget* item);
		virtual void removeAllWidgets();
	protected:
		// ��ʼ��������
		virtual void initItems();
		// ��ʼ��������
		virtual void initContent();
		// ���»����ռ�draw״̬
		void updateScrollDrawState();
	protected:
		// �����������λ��
		CtrlLayout* _content = nullptr;
		// ��
		std::vector<ui::CtrlWidget*> _scrollWidgets;
		// ���λ��
		math::Vector2 _touchPosition;
		
		// ��ֱ�����Ƿ���Ի���
		bool _bHorizontalScroll = false;
		// ˮƽ�����Ƿ���Ի���
		bool _bVerticalScroll = false;
		// �ƶ�ϵ��
		float _movingMultiple = 2;
	};
}