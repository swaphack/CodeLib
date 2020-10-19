#pragma once

#include "LayoutItemBase.h"
#include "macros.h"

namespace ui
{
	/**
	*	������, ������
	*	������ļ�����Ϣ�ڽ�������в����ı䣬�ı��ֻ��CtrlWidget�ļ�����Ϣ
	*/
	class LayoutItem : public LayoutItemBase
	{
	public:
		LayoutItem();
		virtual ~LayoutItem();
	public:
		/**
		*	�������׾���
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	��ȡ���׾���
		*/
		const sys::CSSMargin& getMargin() const;
		/**
		*	��������״̬
		*/
		void setMarginState(const MarginState& state);
		/**
		*	��ȡ����״̬
		*/
		const MarginState& getMarginState() const;
		/**
		*	�����ڲ����
		*/
		void setSize(const sys::CSSSize& size);
		/**
		*	��ȡ�ڲ����
		*/
		const sys::CSSSize& getSize() const;
	public: // ���������صķ���
		/**
		*	���ƶ���
		*/
		bool copy(LayoutItem* item);
		/**
		*	������λ�úʹ�С�����ı�ʱ
		*/
		virtual void resize(const math::Size& size);
	protected:
		// ���׾���
		sys::CSSMargin m_sMargin;
		// ���׾���
		sys::CSSSize m_sSize;
		// ����״̬
		MarginState m_sMarginState;
	};
}