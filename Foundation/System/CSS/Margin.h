#pragma once

namespace sys
{
	/**
	*	±ßÔµ
	*/
	struct Margin
	{
	public:
		// ×ó±ßÁô°×
		float left;
		// ÓÒ±ßÁô°×
		float right;
		// ¶¥²¿Áô°×
		float top;
		// µ×²¿Áô°×
		float bottom;
	public:
		Margin();
		Margin(float left, float right, float bottom, float top);
		Margin(const Margin& margin);
		Margin& operator=(const Margin& margin);
	};
}