#pragma once

#include "Algebra/import.h"

#include "Size.h"

namespace math
{
	/**
	*	矩形框
	*	以左下角为原点
	*/
	struct Rect
	{
	public:
		Rect();
		Rect(float x, float y, float w, float h);
		Rect(const Vector2& origin, const Size& size);
		virtual ~Rect();
	public:
		float getX() const;
		float getY() const;

		float getWidth() const;
		float getHeight() const;

		float getMinX() const;
		float getMaxX() const;
		float getMinY() const;
		float getMaxY() const;

		const Vector2& getOrigin() const;
		
		const Size& getSize() const;
	public:
		/**
		*	设置参数
		*/
		void set(float x, float y, float w, float h);
		void setOrigin(float x, float y);
		void setSize(float x, float y);
		/**
		*	设置参数
		*/
		void set(const Vector2& origin, const Size& size);
		/**
		*	包含点
		*/
		bool contains(float x, float y);
		/**
		*	包含点
		*/
		bool contains(const Vector2& point);
		/**
		*	框相交
		*/
		bool intersect(float x, float y, float w, float h);
		/**
		*	框相交
		*/
		bool intersect(const Rect& rect);

		/**
		*	并集
		*/
		Rect unionRect(const Rect& rect);

		/**
		*	交集
		*/
		Rect intersectRect(const Rect& rect);
	public:
		Rect& operator=(const Rect& rect);
	protected:
		Vector2 _origin;
		Size _size;
	};
}