#pragma once

namespace sys
{
	/**
	*	±ßÔµ
	*/
	struct Margin
	{
		// ×ó±ßÁô°×
		float left;
		// ÓÒ±ßÁô°×
		float right;
		// ¶¥²¿Áô°×
		float top;
		// µ×²¿Áô°×
		float bottom;

		Margin() :left(0), right(0), top(0), bottom(0){}
		Margin(float left, float right, float bottom, float top)
			:left(left), right(right), top(top), bottom(bottom){}

		Margin& operator=(const Margin& margin)
		{
			left = margin.left;
			right = margin.right;
			top = margin.top;
			bottom = margin.bottom;

			return *this;
		}
	};
}