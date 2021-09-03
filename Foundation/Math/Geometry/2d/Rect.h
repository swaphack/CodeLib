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
		*	设置参数
		*/
		void set(float x, float y, float w, float h);
		void setOrigin(float x, float y);
		void setOrigin(const Vector2& origin);
		
		void setSize(float x, float y);
		void setSize(const Size& size);
		/**
		*	设置参数
		*/
		void set(const Vector2& origin, const Size& size);
		/**
		*	包含点
		*/
		bool contains(float x, float y) const;
		/**
		*	包含点
		*/
		bool contains(const Vector2& point) const;
		/**
		*	包含点
		*/
		bool contains(const Vector3& point) const;
		/**
		*	包含点
		*/
		bool contains(const Rect& rect) const;
		/**
		*	包含点
		*/
		bool includes(float x, float y) const;
		/**
		*	包含点
		*/
		bool includes(const Vector2& point) const;
		/**
		*	包含点
		*/
		bool includes(const Vector3& point) const;

		/**
		*	包含框 框在内部
		*/
		bool includes(const Rect& rect) const;

		/**
		*	并集
		*/
		Rect unionRect(const Rect& rect) const;

		/**
		*	交集
		*/
		Rect intersectRect(const Rect& rect) const;
		/**
		*	部分重叠
		*/
		bool isOverlap(const Rect& rect) const;
		/**
		*	获取点所在的锚点位置
		*/  
		math::Vector3 getAnchorPointByPosition(float x, float y);
	public:
		Rect& operator=(const Rect& rect);
	protected:
		// 原点
		Vector2 _origin;
		// 面积
		Size _size;
	};
}