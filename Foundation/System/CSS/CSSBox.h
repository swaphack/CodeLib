#pragma once

#include "CSSSpace.h"

namespace sys
{
	/**
	*	Box 
	*	由外到里顺序 margin->border->padding
	*/
	class CSSBox
	{
	public:
		CSSBox();
		virtual ~CSSBox();
	public:
		void setMargin(const CSSMargin& margin);
	private:
		CSSMargin _margin;
		CSSBorder _border;
		CSSPadding _padding;
	};
}
