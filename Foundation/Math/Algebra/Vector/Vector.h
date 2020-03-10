#pragma once
#include <cstdint>

#include "Basic/Array.h"

namespace math
{
	/**
	*	向量
	*/
	struct Vector : public Array<float>
	{
// 创建轴
#define CREATE_AXIS(Name, Index)\
public: \
	float get##Name() const { return _values[Index]; }\
	void set##Name(float val) { _values[Index] = val; }
	public:
		Vector();
		Vector(int32_t len);
	public:
		/**
		*	向量的模
		*/
		float getMagnitude() const;
		/**
		*	向量的模平方
		*/
		float getMagnitudeSqr() const;
		/**
		*	单位化
		*/
		Vector normalize() const;
	public:
		/**
		*	相加
		*/
		Vector operator+(const Vector& vec) const;
		/**
		*	相减
		*/
		Vector operator-(const Vector& vec) const;
		/**
		*	相乘
		*/
		Vector operator*(float k) const;
		/**
		*	相除
		*/
		Vector operator/(float k) const;
		/**
		*	相加
		*/
		Vector& operator+=(const Vector& vec);
		/**
		*	相减
		*/
		Vector& operator-=(const Vector& vec);
		/**
		*	相乘
		*/
		Vector& operator*=(float k);
		/**
		*	相除
		*/
		Vector& operator/=(float k);
	public:
		/**
		*	相等
		*/
		bool operator==(const Vector& vec);
		/**
		*	不相等
		*/
		bool operator!=(const Vector& vec);
		/**
		*	转换成其他类型
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
		*	向量点积
		*	a * b = |a||b|cos<a, b>
		*/
		static float dot(const Vector& vector0, const Vector& vector1);
		/**
		*	vector1和vector0的夹角余弦值
		*/
		static float cosAngle(const Vector& vector0, const Vector& vector1);
	};
}