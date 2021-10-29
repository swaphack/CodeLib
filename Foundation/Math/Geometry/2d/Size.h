#pragma once

#include "Algebra/Vector/Vector.h"
#include "Algebra/Vector/Vector2.h"
#include "Algebra/Vector/Vector3.h"

namespace math
{
	/**
	*	面积
	*/
	struct Size : public Vector<float, 2>
	{
	public:
		Size();
		Size(float w, float h);
		Size(const Vector2& size);
		Size(const Vector3& size);
		Size(const Size& size);
		virtual ~Size();
	public:
		CREATE_INDEX_VALUE(Width, 0, float);
		CREATE_INDEX_VALUE(Height, 1, float);

		void set(float w, float h);
	public:
		/**
		*	相等
		*/
		bool operator==(const Size& vec) const;
		/**
		*	不相等
		*/
		bool operator!=(const Size& vec) const;
	public:
		operator Vector2()  const;
	};

	/**
	*	面积
	*/
	struct IntSize : public Vector<int, 2>
	{
	public:
		IntSize();
		IntSize(int w, int h);
		IntSize(const IntSize& size);
		virtual ~IntSize();
	public:
		CREATE_INDEX_VALUE(Width, 0, int);
		CREATE_INDEX_VALUE(Height, 1, int);

		void set(int w, int h);
	};
}