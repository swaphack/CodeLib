#pragma once
#include <cstdint>

#include "Basic/Array.h"

namespace math
{
	/**
	*	向量
	*/
	template<typename T, const int Length>
	struct Vector : public Array<T, Length>
	{
		typedef Array<T, Length> base;
	public:
		Vector() {}
		Vector(const Vector& value)
		{
			for (size_t i = 0; i < Length; i++)
			{
				base::setValue(i, value.getValue(i));
			}
		}
		virtual ~Vector() {}
	public:
		/**
		*	向量的模
		*/
		float getMagnitude() const 
		{
			float len = 0;
			for (int i = 0; i < Length; i++)
			{
				len += powf(base::getValue(i), 2);
			}

			return sqrt(len);
		}
		/**
		*	向量的模平方
		*/
		float getSqrMagnitude() const

		{
			float len = 0;
			for (int i = 0; i < Length; i++)
			{
				len += powf(base::getValue(i), 2);
			}

			return len;
		}
		/**
		*	单位化
		*/
		Vector normalize() const
		{
			float magn = this->getMagnitude();
			if (magn == 0)
			{
				return *this;
			}

			Vector vec;
			for (int i = 0; i < Length; i++)
			{
				vec.setValue(i, base::getValue(i) / magn);
			}

			return vec;
		}
	public:
		/**
		*	相加
		*/
		Vector operator+(const Vector& vec) const
		{
			Vector target = *this;
			for (int i = 0; i < Length; i++)
			{
				target[i] += vec[i];
			}
			return target;
		}
		/**
		*	相减
		*/
		Vector operator-(const Vector& vec) const
		{
			Vector target = *this;
			for (int i = 0; i < Length; i++)
			{
				target[i] -= vec[i];
			}
			return target;
		}
		/**
		*	相乘
		*/
		Vector operator*(float k) const
		{
			assert(k != 0);

			Vector target = *this;
			for (int i = 0; i < Length; i++)
			{
				target[i] *= k;
			}
			return target;
		}
		/**
		*	相除
		*/
		Vector operator/(float k) const
		{
			assert(k != 0);

			Vector target = *this;
			for (int i = 0; i < Length; i++)
			{
				target[i] /= k;
			}
			return target;
		}
		/**
		*	相加
		*/
		Vector& operator+=(const Vector& vec) 
		{
			for (int i = 0; i < Length; i++)
			{
				base::setValue(i, base::getValue(i) + vec.getValue(i));
			}
			return *this;
		}
		/**
		*	相减
		*/
		Vector& operator-=(const Vector& vec)
		{
			for (int i = 0; i < Length; i++)
			{
				base::setValue(i, base::getValue(i) - vec.getValue(i));
			}
			return *this;
		}
		/**
		*	相乘
		*/
		Vector& operator*=(float k)
		{
			for (int i = 0; i < Length; i++)
			{
				base::setValue(i, base::getValue(i) * k);
			}
			return *this;
		}
		/**
		*	相除
		*/
		Vector& operator/=(float k)
		{
			assert(k != 0);

			for (int i = 0; i < Length; i++)
			{
				base::setValue(i, base::getValue(i) / k);
			}
			return *this;
		}
	public:
		/**
		*	相等
		*/
		bool operator==(const Vector& vec)
		{
			for (int i = 0; i < Length; i++)
			{
				if (base::getValue(i) != vec.getValue(i))
				{
					return false;
				}
			}

			return true;
		}
		/**
		*	不相等
		*/
		bool operator!=(const Vector& vec)
		{
			for (int i = 0; i < Length; i++)
			{
				if (base::getValue(i) != vec.getValue(i))
				{
					return true;
				}
			}

			return false;
		}
		/**
		*	转换成其他类型
		*/
		template<typename T, typename=std::enable_if<std::is_base_of<Vector, T>::value, T>::type>
		operator T() 
		{
			T t;
			Vector* p = &t;
			p->assign(base::getValue());
			return t;
		}
	public:
		/**
		*	向量点积
		*	a * b = |a||b|cos<a, b>
		*/
		static float dot(const Vector& vector0, const Vector& vector1)
		{
			float value = 0;
			for (int32_t i = 0; i < Length; i++)
			{
				value += vector0.getValue(i) * vector1.getValue(i);
			}

			return value;
		}
		/**
		*	vector1和vector0的夹角余弦值
		*/
		static float cosAngle(const Vector& vector0, const Vector& vector1)
		{
			float a = vector0.getMagnitude();
			float b = vector1.getMagnitude();

			assert(a != 0 && b != 0);

			return Vector::dot(vector0, vector1) / (a * b);
		}
	};
}