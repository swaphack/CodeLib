#include "Margin.h"

using namespace sys;

Margin& Margin::operator=(const Margin& margin)
{
	left = margin.left;
	right = margin.right;
	top = margin.top;
	bottom = margin.bottom;

	return *this;
}

Margin::Margin(float left, float right, float bottom, float top) :left(left), right(right), top(top), bottom(bottom)
{

}

Margin::Margin() : left(0), right(0), top(0), bottom(0)
{

}

Margin::Margin(const Margin& margin)
{
	left = margin.left;
	right = margin.right;
	top = margin.top;
	bottom = margin.bottom;
}
