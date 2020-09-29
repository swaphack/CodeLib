#pragma once
#include "CSSNumber.h"

namespace sys
{
	/**
	*	���׷��� ��������
	*/
	struct CSSSpace
	{
	public:
		CSSSpace();
		virtual ~CSSSpace();
	public:
		/**
		*	�������
		*/
		void setLeft(NumberType eType, float value);
		/**
		*	�������
		*/
		void setLeft(const CSSNumber& value);
		/**
		*	�������
		*/
		const CSSNumber& getLeft() const;
		/**
		*	�ұ�����
		*/
		void setRight(NumberType eType, float value);
		/**
		*	�ұ�����
		*/
		void setRight(const CSSNumber& value);
		/**
		*	�ұ�����
		*/
		const CSSNumber& getRight() const;
		/**
		*	��������
		*/
		void setTop(NumberType eType, float value);
		/**
		*	��������
		*/
		void setTop(const CSSNumber& value);
		/**
		*	��������
		*/
		const CSSNumber& getTop() const;
		/**
		*	�ײ�����
		*/
		void setBottom(NumberType eType, float value);
		/**
		*	�ײ�����
		*/
		void setBottom(const CSSNumber& value);
		/**
		*	�ײ�����
		*/
		const CSSNumber& getBottom() const;
	protected:
		// �������
		CSSNumber _left;
		// �ұ�����
		CSSNumber _right;
		// ��������
		CSSNumber _top;
		// �ײ�����
		CSSNumber _bottom;
	};

	typedef CSSSpace CSSMargin;
	typedef CSSSpace CSSBorder;
	typedef CSSSpace CSSPadding;
}