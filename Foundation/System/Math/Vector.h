#pragma once

namespace sys
{
	// 3d
	struct Vector
	{
		float x;
		float y;
		float z;

		Vector() :x(0), y(0), z(0){}
		Vector(float x, float y, float z = 0) :x(x), y(y), z(z){}
		Vector(const Vector& vector) :x(vector.x), y(vector.y), z(vector.z){}

		void add(const Vector& vector)
		{
			x += vector.x;
			y += vector.y;
			z += vector.z;
		}

		void sub(const Vector& vector)
		{
			x -= vector.x;
			y -= vector.y;
			z -= vector.z;
		}

		void mult(const Vector& vector)
		{
			x *= vector.x;
			y *= vector.y;
			z *= vector.z;
		}

		void div(const Vector& vector)
		{
			x /= vector.x;
			y /= vector.y;
			z /= vector.z;
		}

		void mult(const float ratio)
		{
			x *= ratio;
			y *= ratio;
			z *= ratio;
		}

		bool isZero()
		{
			return x == 0.0f && y == 0.0f && z == 0.0f;
		}

		virtual void operator=(const Vector& vector)
		{
			x = vector.x;
			y = vector.y;
			z = vector.z;
		}

	public:
		static Vector Zero;

		static Vector One;
	};

	__declspec(selectany) Vector Vector::Zero;
	__declspec(selectany) Vector Vector::One = Vector(1,1,1);
}