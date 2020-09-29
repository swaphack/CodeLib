#pragma once
#include "CSSNumber.h"

namespace sys
{
	/**
	*	Áô°×·½Ïò ÉÏÓÒÏÂ×ó
	*/
	struct CSSSpace
	{
	public:
		CSSSpace();
		virtual ~CSSSpace();
	public:
		/**
		*	×ó±ßÁô°×
		*/
		void setLeft(NumberType eType, float value);
		/**
		*	×ó±ßÁô°×
		*/
		void setLeft(const CSSNumber& value);
		/**
		*	×ó±ßÁô°×
		*/
		const CSSNumber& getLeft() const;
		/**
		*	ÓÒ±ßÁô°×
		*/
		void setRight(NumberType eType, float value);
		/**
		*	ÓÒ±ßÁô°×
		*/
		void setRight(const CSSNumber& value);
		/**
		*	ÓÒ±ßÁô°×
		*/
		const CSSNumber& getRight() const;
		/**
		*	¶¥²¿Áô°×
		*/
		void setTop(NumberType eType, float value);
		/**
		*	¶¥²¿Áô°×
		*/
		void setTop(const CSSNumber& value);
		/**
		*	¶¥²¿Áô°×
		*/
		const CSSNumber& getTop() const;
		/**
		*	µ×²¿Áô°×
		*/
		void setBottom(NumberType eType, float value);
		/**
		*	µ×²¿Áô°×
		*/
		void setBottom(const CSSNumber& value);
		/**
		*	µ×²¿Áô°×
		*/
		const CSSNumber& getBottom() const;
	protected:
		// ×ó±ßÁô°×
		CSSNumber _left;
		// ÓÒ±ßÁô°×
		CSSNumber _right;
		// ¶¥²¿Áô°×
		CSSNumber _top;
		// µ×²¿Áô°×
		CSSNumber _bottom;
	};

	typedef CSSSpace CSSMargin;
	typedef CSSSpace CSSBorder;
	typedef CSSSpace CSSPadding;
}