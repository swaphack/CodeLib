#pragma once

#include "LayoutItemBase.h"

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
		*	���ñ�Ե����
		*/
		void setMargin(const sys::CSSMargin& margin);
		/**
		*	��ȡ��Ե����
		*/
		const sys::CSSMargin& getMargin() const;
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
		// ��Ե����
		sys::CSSMargin m_sMargin;
		// ��Ե����
		sys::CSSSize m_sSize;
	};
}