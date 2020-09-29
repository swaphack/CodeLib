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
		*	宽度
		*/
		void setWidth(NumberType eType, float value);
		/**
		*	宽度
		*/
		void setWidth(const CSSNumber& value);
		/**
		*	宽度
		*/
		const CSSNumber& getWidth() const;
		/**
		*	高度
		*/
		void setHeight(NumberType eType, float value);
		/**
		*	高度
		*/
		void setHeight(const CSSNumber& value);
		/**
		*	高度
		*/
		const CSSNumber& getHeight() const;
	protected:
		// 宽度
		CSSNumber _width;
		// 高度
		CSSNumber _height;
	};
}
