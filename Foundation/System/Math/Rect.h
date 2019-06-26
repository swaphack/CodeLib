#pragma once
#include "Vector2.h"

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

		bool contains(const Vector2& point32)
		{
			return contains(point32.x, point32.y);
		}

		bool intersect(float _x, float _y, float _w, float _h)
		{
			return !(getMaxX() < _x ||
				_x + _w < getMinX() ||
				getMaxY() < _y ||
				_y + _h < getMinY());
		}

		bool intersect(const Rect& rect)
		{
			return intersect(rect.x, rect.y, rect.width, rect.height);
		}

		// 并集
		Rect unionRect(const Rect& rect)
		{
			Rect* pRect = &(Rect&)rect;
			
			float x0 = this->getMinX() < pRect->getMinX() ? this->getMinX() : pRect->getMinX();
			float x1 = this->getMaxX() > pRect->getMaxX() ? this->getMaxX() : pRect->getMaxX();
			float y0 = this->getMinY() < pRect->getMinY() ? this->getMinY() : pRect->getMinY();
			float y1 = this->getMaxY() > pRect->getMaxY() ? this->getMaxY() : pRect->getMaxY();

			Rect result;
			result.x = x0;
			result.y = y0;
			result.width = x1 - x0;
			result.height = y1 - y0;

			return result;
		}

		// 交集
		Rect intersectRect(const Rect& rect)
		{
			if (!intersect(rect))
			{
				return Rect::Zero;
			}

			Rect* pRect = &(Rect&)rect;

			Rect merge = unionRect(rect);
			float x0 = this->getMinX() == merge.getMinX() ? pRect->getMinX() : this->getMinX();
			float x1 = this->getMaxX() == merge.getMaxX() ? pRect->getMaxX() : this->getMaxX();
			float y0 = this->getMinY() == merge.getMinY() ? pRect->getMinY() : this->getMinY();
			float y1 = this->getMaxY() == merge.getMaxY() ? pRect->getMaxY() : this->getMaxY();

			Rect result;
			result.x = x0;
			result.y = y0;
			result.width = x1 - x0;
			result.height = y1 - y0;
			return result;

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