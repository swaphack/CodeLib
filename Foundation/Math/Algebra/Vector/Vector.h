#pragma once
#include <cstdint>

#include "Basic/Array.h"

namespace math
{
	/**
	*	����
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
		*	������ģ
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
		*	������ģƽ��
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
		*	��λ��
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
		*	���
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
		*	���
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
		*	���
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
		*	���
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
		*	���
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
		*	���
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
		*	���
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
		*	���
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
		*	���
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
		*	�����
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
		*	ת������������
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
		*	�������
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
		*	vector1��vector0�ļн�����ֵ
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