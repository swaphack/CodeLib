#pragma once

#include "Algebra/import.h"

#include "Size.h"

namespace math
{
	/**
	*	���ο�
	*	�����½�Ϊԭ��
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
		*	���ò���
		*/
		void set(float x, float y, float w, float h);
		void setOrigin(float x, float y);
		void setSize(float x, float y);
		/**
		*	���ò���
		*/
		void set(const Vector2& origin, const Size& size);
		/**
		*	������
		*/
		bool contains(float x, float y);
		/**
		*	������
		*/
		bool contains(const Vector2& point);
		/**
		*	���ཻ
		*/
		bool intersect(float x, float y, float w, float h);
		/**
		*	���ཻ
		*/
		bool intersect(const Rect& rect);

		/**
		*	����
		*/
		Rect unionRect(const Rect& rect);

		/**
		*	����
		*/
		Rect intersectRect(const Rect& rect);
	public:
		Rect& operator=(const Rect& rect);
	protected:
		Vector2 _origin;
		Size _size;
	};
}