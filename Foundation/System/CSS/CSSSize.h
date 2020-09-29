#pragma once

#include "CSSNumber.h"

namespace sys
{
	struct CSSSize
	{
	public:
		CSSSize();
		virtual ~CSSSize();
	public:
		/**
		*	���
		*/
		void setWidth(NumberType eType, float value);
		/**
		*	���
		*/
		void setWidth(const CSSNumber& value);
		/**
		*	���
		*/
		const CSSNumber& getWidth() const;
		/**
		*	�߶�
		*/
		void setHeight(NumberType eType, float value);
		/**
		*	�߶�
		*/
		void setHeight(const CSSNumber& value);
		/**
		*	�߶�
		*/
		const CSSNumber& getHeight() const;
	protected:
		// ���
		CSSNumber _width;
		// �߶�
		CSSNumber _height;
	};
}
