#pragma once

#include "Layout/LayoutItem.h"
#include "ui_common.h"

namespace ui
{
	class Layout;

	static const int LAYOUT_SIZE_MIN_WIDTH = 0;
	static const int LAYOUT_SIZE_MIN_HEIGHT = 0;
	static const int LAYOUT_SIZE_MAX_WIDTH = 65536;
	static const int LAYOUT_SIZE_MAX_HEIGHT = 65536;

	/**
	*	������, ������
	*	������ļ�����Ϣ�ڽ�������в����ı䣬�ı��ֻ��widget�ļ�����Ϣ
	*/
	class LayoutItemEx : public LayoutItem
	{
	public:
		LayoutItemEx();
		virtual ~LayoutItemEx();
	public: // �̶����������
		/**
		*	��ȡ��С�������Ϣ
		*/
		const sys::Size& getMinSize();
		/**
		*	������С�������Ϣ
		*/
		void setMinSize(float width, float height);
		/**
		*	������С�������Ϣ
		*/
		void setMinSize(const sys::Size& size);
		/**
		*	��ȡ��󳤿����Ϣ
		*/
		const sys::Size& getMaxSize();
		/**
		*	������󳤿����Ϣ
		*/
		void setMaxSize(float width, float height);
		/**
		*	������󳤿����Ϣ
		*/
		void setMaxSize(const sys::Size& size);
		/**
		*	��ȡ�ڴ����С�ı�ʱ�����ҵ�������
		*/
		SizePolicy& getSizePolicy();
		/**
		*	��ȡ�ڴ����С�ı�ʱ�����ҵ�������
		*/
		void setSizePolicy(const SizePolicy& policy);
	public: // ���������صķ���
		/**
		*	��ȡ���ֵ���С���
		*/
		virtual sys::Size getLayoutMinSize();
		/**
		*	��ȡ���ֵ�������
		*/
		virtual sys::Size getLayoutMaxSize();
		/**
		*	���ƶ���
		*/
		virtual bool copy(LayoutItemEx* item);
	protected:
		// ��С���
		sys::Size m_sMinSize;
		// ������
		sys::Size m_sMaxSize;
		// ��С��������
		SizePolicy m_spAdjust;
	};
}