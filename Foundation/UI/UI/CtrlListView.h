#pragma once

#include "CtrlScrollView.h"

namespace ui
{

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
		*	������Ĵ�С
		*/
		void setItemSize(const sys::CSSSize& size);
		/**
		*	������Ĵ�С
		*/
		void setItemSize(float width, float height);
		/**
		*	��ȡ������Ĵ�С
		*/
		const sys::CSSSize& getItemSize();
		/**
		*	�Ƿ�ʹ�����ô�С
		*/
		bool isUseItemSize() const;
		/**
		*	�Ƿ�ʹ�����ô�С
		*/
		void setUseItemSize(bool bUsed);
		/**
		*	�Ƿ������ʾ
		*/
		bool isShowInCenter() const;
		/**
		*	�Ƿ������ʾ
		*/
		void setShowInCenter(bool bCenter);
	public:
		/**
		*	���һ����
		*/
		virtual void addItem(CtrlWidget* item, int zOrder = 0);
	protected:
		// ������
		virtual void handMovedTouch(const math::Vector2& touchPoint);
	protected:
		// ��ʼ��������
		virtual void initItems();
		// ��ʼ��������
		virtual void initContent();
	protected:
		// ��Ĵ�С
		sys::CSSSize _itemSize;
		// �Ƿ�ʹ�����õĴ�С
		bool _useItemSize = false;

		// �Ƿ������ʾ
		bool _showInCenter = false;
	};
}
