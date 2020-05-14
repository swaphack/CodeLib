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
		float left = 0;
		// ÓÒ±ßÁô°×
		float right = 0;
		// ¶¥²¿Áô°×
		float top = 0;
		// µ×²¿Áô°×
		float bottom = 0;
	public:
		Margin();
		Margin(float left, float right, float bottom, float top);
		Margin(const Margin& margin);
		Margin& operator=(const Margin& margin);
	};
}