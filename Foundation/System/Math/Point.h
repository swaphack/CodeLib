#pragma once

namespace sys
{
	// 2d
	struct Point
	{
		float x;
		float y;

		Point() :x(0), y(0){}
		Point(float x, float y) :x(x), y(y){}

		void add(const Point& point)
		{
			x += point.x;
			y += point.y;
		}

		void sub(const Point& point)
		{
			x -= point.x;
			y -= point.y;
		}

		void mult(const Point& point)
		{
			x *= point.x;
			y *= point.y;
		}

		void div(const Point& point)
		{
			x /= point.x;
			y /= point.y;
		}

		void mult(const float ratio)
		{
			x *= ratio;
			y *= ratio;
		}
	};
}