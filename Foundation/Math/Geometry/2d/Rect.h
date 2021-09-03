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
		Rect(const Vector2& orgin, const Size& size);
		Rect(const Vector2& orgin, const Vector2& size);
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
		void setOrigin(const Vector2& origin);
		
		void setSize(float x, float y);
		void setSize(const Size& size);
		/**
		*	���ò���
		*/
		void set(const Vector2& origin, const Size& size);
		/**
		*	������
		*/
		bool contains(float x, float y) const;
		/**
		*	������
		*/
		bool contains(const Vector2& point) const;
		/**
		*	������
		*/
		bool contains(const Vector3& point) const;
		/**
		*	������
		*/
		bool contains(const Rect& rect) const;
		/**
		*	������
		*/
		bool includes(float x, float y) const;
		/**
		*	������
		*/
		bool includes(const Vector2& point) const;
		/**
		*	������
		*/
		bool includes(const Vector3& point) const;

		/**
		*	������ �����ڲ�
		*/
		bool includes(const Rect& rect) const;

		/**
		*	����
		*/
		Rect unionRect(const Rect& rect) const;

		/**
		*	����
		*/
		Rect intersectRect(const Rect& rect) const;
		/**
		*	�����ص�
		*/
		bool isOverlap(const Rect& rect) const;
		/**
		*	��ȡ�����ڵ�ê��λ��
		*/  
		math::Vector3 getAnchorPointByPosition(float x, float y);
	public:
		Rect& operator=(const Rect& rect);
	protected:
		// ԭ��
		Vector2 _origin;
		// ���
		Size _size;
	};
}