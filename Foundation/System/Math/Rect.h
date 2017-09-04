#pragma once

namespace sys
{
	/**
	*	矩形框
	*	已左下角为原点
	*/
	struct Rect
	{
		float x;
		float y;
		float width;
		float height;

		float getMinX() { return x; }
		float getMaxX() { return x + width; }
		float getMinY() { return y; }
		float getMaxY() { return y + height; }

		Rect() :x(0), y(0), width(0), height(0){}
		Rect(float x, float y, float w, float h) :x(x), y(y), width(w), height(h){}

		bool contains(float _x, float _y)
		{
			return (_x >= getMinX() && _x <= getMaxX())
				&& (_y >= getMinY() && _y <= getMaxY());
		}

		bool intersect(float _x, float _y, float _w, float _h)
		{
			return !(getMaxX() < _x ||
				_x + _w < getMinX() ||
				getMaxY() < _y ||
				_y + _h < getMinY());
		}

		Rect& operator=(const Rect& rect)
		{
			x = rect.x;
			y = rect.y;
			width = rect.width;
			height = rect.height;

			return *this;
		}


		static Rect Zero;
	};

	__declspec(selectany) Rect Rect::Zero = Rect();
}