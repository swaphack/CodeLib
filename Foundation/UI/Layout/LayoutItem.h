#pragma once

#include "LayoutItemBase.h"
#include "macros.h"

namespace ui
{
	class CtrlWidget;
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
		static LayoutItem* create();
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
		void setMarginState(bool left, bool right, bool top, bool bottom);
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
		/**
		*	��ȡ�ڲ����
		*/
		sys::CSSSize& getSize();
	public:
		/**
		*	��������
		*/
		void setMargin(float top, float right, float bottom, float left);
		/**
		*	���þ������ƫ����
		*/
		void setLeftMargin(float offset, bool enable = true);
		/**
		*	���þ����ұ�ƫ����
		*/
		void setRightMargin(float offset, bool enable = true);
		/**
		*	���þ��붥��ƫ����
		*/
		void setTopMargin(float offset, bool enable = true);
		/**
		*	���þ���ײ�ƫ����
		*/
		void setBottomMargin(float offset, bool enable = true);
		/**
		*	ȡ���������ƫ��������
		*/
		void unsetLeftMargin();
		/**
		*	ȡ�������ұ�ƫ��������
		*/
		void unsetRightMargin();
		/**
		*	ȡ�����붥��ƫ��������
		*/
		void unsetTopMargin();
		/**
		*	ȡ������ײ�ƫ��������
		*/
		void unsetBottomMargin();
		/**
		*	���ÿհ�״̬
		*/
		void unsetMarginState();
	public:
		/**
		*	���ÿ��
		*/
		void setWidth(float value);
		/**
		*	���ø߶�
		*/
		void setHeight(float value);
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
		void setWidget(CtrlWidget* widget);
	protected:
		// ���׾���
		sys::CSSMargin m_sMargin;
		// ���׾���
		sys::CSSSize m_sSize;
		// ����״̬
		MarginState m_sMarginState;
	};
}