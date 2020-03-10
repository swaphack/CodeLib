#pragma once
#include <cstdint>

#include "Basic/Array.h"

namespace math
{
	/**
	*	����
	*/
	struct Vector : public Array<float>
	{
// ������
#define CREATE_AXIS(Name, Index)\
public: \
	float get##Name() const { return _values[Index]; }\
	void set##Name(float val) { _values[Index] = val; }
	public:
		Vector();
		Vector(int32_t len);
	public:
		/**
		*	������ģ
		*/
		float getMagnitude() const;
		/**
		*	������ģƽ��
		*/
		float getMagnitudeSqr() const;
		/**
		*	��λ��
		*/
		Vector normalize() const;
	public:
		/**
		*	���
		*/
		Vector operator+(const Vector& vec) const;
		/**
		*	���
		*/
		Vector operator-(const Vector& vec) const;
		/**
		*	���
		*/
		Vector operator*(float k) const;
		/**
		*	���
		*/
		Vector operator/(float k) const;
		/**
		*	���
		*/
		Vector& operator+=(const Vector& vec);
		/**
		*	���
		*/
		Vector& operator-=(const Vector& vec);
		/**
		*	���
		*/
		Vector& operator*=(float k);
		/**
		*	���
		*/
		Vector& operator/=(float k);
	public:
		/**
		*	���
		*/
		bool operator==(const Vector& vec);
		/**
		*	�����
		*/
		bool operator!=(const Vector& vec);
		/**
		*	ת������������
		*/
		template<typename T, typename=std::enable_if<std::is_base_of<Vector, T>::value, T>::type>
		operator T() 
		{
			T t;
			Vector* p = &t;
			p->set(this->_values, this->_length);
			return t;
		}
	public:
		/**
		*	�������
		*	a * b = |a||b|cos<a, b>
		*/
		static float dot(const Vector& vector0, const Vector& vector1);
		/**
		*	vector1��vector0�ļн�����ֵ
		*/
		static float cosAngle(const Vector& vector0, const Vector& vector1);
	};
}