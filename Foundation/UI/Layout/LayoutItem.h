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
		*	��ȡ���׾���
		*/
		sys::CSSMargin& getMargin();
		/**
		*	��������״̬
		*/
		void setMarginState(const MarginState& state);
		/**
		*	��ȡ����״̬
		*/
		const MarginState& getMarginState() const;
		/**
		*	��ȡ����״̬
		*/
		MarginState& getMarginState();
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
	public:
		/**
		*	��ӿؼ�
		*/
		void addWidget(render::CtrlWidget* widget);
	protected:
		// ���׾���
		sys::CSSMargin m_sMargin;
		// ���׾���
		sys::CSSSize m_sSize;
		// ����״̬
		MarginState m_sMarginState;
	};
}