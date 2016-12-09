#pragma once

namespace sys
{
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

		bool insect(float _x, float _y)
		{
			return (_x >= getMinX() && _x <= getMaxX())
				&& (_y >= getMinY() && _y <= getMaxY());
		}

		bool insert(float _x, float _y, float _w, float _h)
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
		}


		static Rect Zero;
	};

	__declspec(selectany) Rect Rect::Zero = Rect();
}