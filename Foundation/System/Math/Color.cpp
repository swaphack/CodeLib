#include "Color.h"

using namespace sys;

Color3B::Color3B() :red(COLOR_UCHAR_VALUE), green(COLOR_UCHAR_VALUE), blue(COLOR_UCHAR_VALUE)
{

}

Color3B::Color3B(uchar r, uchar g, uchar b) : red(r), green(g), blue(b)
{

}

bool Color3B::isEquals(const Color3B& color)
{
	return red == color.red	 && green == color.green && blue == color.blue;
}

void Color3B::operator=(const Color3B& color)
{
	red = color.red;
	green = color.green;
	blue = color.blue;
}

void Color3B::add(const Color3B& color)
{
	red += color.red;
	green += color.green;
	blue += color.blue;
}

void Color3B::sub(const Color3B& color)
{
	red -= color.red;
	green -= color.green;
	blue -= color.blue;
}

void Color3B::mult(const Color3B& color)
{
	red *= color.red;
	green *= color.green;
	blue *= color.blue;
}

void Color3B::mult(const float ratio)
{
	red = (uchar)(red * ratio);
	green = (uchar)(red * ratio);
	blue = (uchar)(red * ratio);
}

void Color3B::div(const Color3B& color)
{
	red /= color.red;
	green /= color.green;
	blue /= color.blue;
}
//////////////////////////////////////////////////////////////////////////

Color3F::Color3F() :red(1), green(1), blue(1)
{

}

Color3F::Color3F(float r, float g, float b) : red(r), green(g), blue(b)
{

}

bool Color3F::isEquals(const Color3F& color)
{
	return red == color.red	 && green == color.green && blue == color.blue;
}

void Color3F::operator=(const Color3F& color)
{
	red = color.red;
	green = color.green;
	blue = color.blue;
}

void Color3F::add(const Color3F& color)
{
	red += color.red;
	green += color.green;
	blue += color.blue;
	adjust();
}

void Color3F::sub(const Color3F& color)
{
	red -= color.red;
	green -= color.green;
	blue -= color.blue;
	adjust();
}

void Color3F::mult(const Color3F& color)
{
	red *= color.red;
	green *= color.green;
	blue *= color.blue;
	adjust();
}

void Color3F::mult(const float ratio)
{
	red *= ratio;
	green *= ratio;
	blue *= ratio;
	adjust();
}

void Color3F::div(const Color3F& color)
{
	red /= color.red;
	green /= color.green;
	blue /= color.blue;
	adjust();
}

void Color3F::adjust()
{
	ADJUST_DURATION_VALUE_RANGE(red, 0, 1, 1);
	ADJUST_DURATION_VALUE_RANGE(green, 0, 1, 1);
	ADJUST_DURATION_VALUE_RANGE(blue, 0, 1, 1);
}

//////////////////////////////////////////////////////////////////////////


Color4B::Color4B() :red(COLOR_UCHAR_VALUE), green(COLOR_UCHAR_VALUE), blue(COLOR_UCHAR_VALUE), alpha(COLOR_UCHAR_VALUE)
{

}

Color4B::Color4B(uchar r, uchar g, uchar b, uchar a) : red(r), green(g), blue(b), alpha(a)
{

}

bool Color4B::isEquals(const Color4B& color)
{
	return red == color.red	 && green == color.green && blue == color.blue && alpha == color.alpha;
}

void Color4B::add(const Color4B& color)
{
	red += color.red;
	green += color.green;
	blue += color.blue;
	alpha += color.alpha;
	adjust();
}

void Color4B::sub(const Color4B& color)
{
	red -= color.red;
	green -= color.green;
	blue -= color.blue;
	alpha -= color.alpha;
	adjust();
}

void Color4B::mult(const Color4B& color)
{
	red *= color.red;
	green *= color.green;
	blue *= color.blue;
	alpha *= color.alpha;
	adjust();
}

void Color4B::mult(const float ratio)
{
	red = (uchar)(red * ratio);
	green = (uchar)(red * ratio);
	blue = (uchar)(red * ratio);
	alpha = (uchar)(red * ratio);
	adjust();
}

void Color4B::div(const Color4B& color)
{
	red /= color.red;
	green /= color.green;
	blue /= color.blue;
	alpha /= color.alpha;
	adjust();
}

void Color4B::adjust()
{
	ADJUST_DURATION_VALUE_RANGE(red, 0, 255, 255);
	ADJUST_DURATION_VALUE_RANGE(green, 0, 255, 255);
	ADJUST_DURATION_VALUE_RANGE(blue, 0, 255, 255);
	ADJUST_DURATION_VALUE_RANGE(alpha, 0, 255, 255);
}

void Color4B::operator=(const Color4B& color)
{
	red = color.red;
	green = color.green;
	blue = color.blue;
	alpha = color.alpha;
}


//////////////////////////////////////////////////////////////////////////


Color4F::Color4F() :red(1), green(1), blue(1), alpha(1)
{

}

Color4F::Color4F(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a)
{

}

bool Color4F::isEquals(const Color4F& color)
{
	return red == color.red	 && green == color.green && blue == color.blue && alpha == color.alpha;
}

void Color4F::operator=(const Color4F& color)
{
	red = color.red;
	green = color.green;
	blue = color.blue;
	alpha = color.alpha;
}

void Color4F::add(const Color4F& color)
{
	red += color.red;
	green += color.green;
	blue += color.blue;
	alpha += color.alpha;
	adjust();
}

void Color4F::sub(const Color4F& color)
{
	red -= color.red;
	green -= color.green;
	blue -= color.blue;
	alpha -= color.alpha;
	adjust();
}

void Color4F::mult(const Color4F& color)
{
	red *= color.red;
	green *= color.green;
	blue *= color.blue;
	alpha *= color.alpha;
	adjust();
}

void Color4F::mult(const float ratio)
{
	red *= ratio;
	green *= ratio;
	blue *= ratio;
	alpha *= ratio;
	adjust();
}

void Color4F::div(const Color4F& color)
{
	red /= color.red;
	green /= color.green;
	blue /= color.blue;
	alpha /= color.alpha;
	adjust();
}

void Color4F::adjust()
{
	ADJUST_DURATION_VALUE_RANGE(red, 0, 1, 1);
	ADJUST_DURATION_VALUE_RANGE(green, 0, 1, 1);
	ADJUST_DURATION_VALUE_RANGE(blue, 0, 1, 1);
	ADJUST_DURATION_VALUE_RANGE(alpha, 0, 1, 1);
}
//////////////////////////////////////////////////////////////////////////
void sys::convertColor3BTo3F(const Color3B & b3, Color3F & f3)
{
	f3.red = b3.red / COLOR_FLOAT_VALUE;
	f3.green = b3.green / COLOR_FLOAT_VALUE;
	f3.blue = b3.blue / COLOR_FLOAT_VALUE;
}

void sys::convertColor3FTo3B(const Color3F & f3, Color3B & b3)
{
	b3.red = (uchar)(f3.red * COLOR_FLOAT_VALUE);
	b3.green = (uchar)(f3.green * COLOR_FLOAT_VALUE);
	b3.blue = (uchar)(f3.blue * COLOR_FLOAT_VALUE);
}

void sys::convertColor4BTo4F(const Color4B & b4, Color4F & f4)
{
	f4.red = b4.red / COLOR_FLOAT_VALUE;
	f4.green = b4.green / COLOR_FLOAT_VALUE;
	f4.blue = b4.blue / COLOR_FLOAT_VALUE;
	f4.alpha = b4.alpha / COLOR_FLOAT_VALUE;
}

void sys::convertColor4FTo4B(const Color4F & f4, Color4B & b4)
{
	b4.red = (uchar)(f4.red * COLOR_FLOAT_VALUE);
	b4.green = (uchar)(f4.green * COLOR_FLOAT_VALUE);
	b4.blue = (uchar)(f4.blue * COLOR_FLOAT_VALUE);
	b4.alpha = (uchar)(f4.alpha * COLOR_FLOAT_VALUE);
}
