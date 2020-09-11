#pragma once

#include <cstdarg>

namespace math
{
	/**
	*	Բ����
	*/
#ifndef PI
#define PI 3.14159265358979323846f
#endif
	/**
	*	��Ȼ����
	*/
#ifndef E
#define E 3.14159265358979323846f
#endif

	/**
	*	����
	*/
#ifndef EPSILON
#define EPSILON (1.0e-6)
#endif
	/**
	*	�Ƕ�ת����
	*/
#define ANGLE_TO_RADIAN(x) (x * PI / 180)
	/**
	*	����ת�Ƕ�
	*/
#define RADIAN_TO_ANGLE(x) (x * 180 / PI)
	/**
	*	ȡ�����е����ֵ
	*/
#define MAX(a,b)	((a) > (b) ? (a) : (b))
	/**
	*	ȡ�����е���Сֵ
	*/
#define MIN(a,b)	((a) < (b) ? (a) : (b))
	/**
	*	��Ŀ��ֵת����ָ��������
	*/
#ifndef ADJUST_DURATION_VALUE_RANGE
#define ADJUST_DURATION_VALUE_RANGE(a, min, max, range)\
		while (a < min) a+= range; while (a > max) a-=range;
#endif
	/**
	*	�ж����������������ķ�Χ���Ƿ����
	*/
#define APPROXIMATELY(a, b) (fabs((a) - (b)) <= EPSILON)

	/**
	*	�������Ա
	*/
#ifndef CREATE_CLASS_MEMBER_WITH_DEFAULT
#define CREATE_CLASS_MEMBER_WITH_DEFAULT(Type, Name, DefaultValue) \
public:\
	Type get##Name() const { return _##Name; }\
	void set##Name(Type val) { _##Name = val; } \
private: Type _##Name = DefaultValue;
#endif

	/**
	*	�������Ա
	*/
#ifndef CREATE_CLASS_MEMBER
#define CREATE_CLASS_MEMBER(Type, Name) \
public:\
	Type get##Name() const { return _##Name; }\
	void set##Name(Type val) { _##Name = val; } \
private: Type _##Name;
#endif

	/**
	*	�������Ա
	*/
#ifndef CREATE_CLASS_VECTOR_MEMBER
#define CREATE_CLASS_VECTOR_MEMBER(Type, Name, VectorName, Index) \
public:\
	Type get##Name() const { return (Type)VectorName[Index]; }\
	void set##Name(Type val) { VectorName[Index] = val; }
#endif

	template<typename T>
	void GET_VA_ARG(T& value, va_list& ap)
	{
		const char* name = typeid(T).name();
		if (strcmp(name, typeid(char).name()) == 0
			|| strcmp(name, typeid(signed char).name()) == 0
			|| strcmp(name, typeid(unsigned char).name()) == 0
			|| strcmp(name, typeid(short).name()) == 0
			|| strcmp(name, typeid(unsigned short).name()) == 0
			|| strcmp(name, typeid(signed short).name()) == 0)
		{
			value = (T)va_arg(ap, int);
		}
		else if (strcmp(name, typeid(float).name()) == 0)
		{
			value = (T)va_arg(ap, double);
		}
		else
		{
			value = (T)va_arg(ap, T);
		}
	}

	template<typename T>
	T* GET_PARAMETERS(int length, T start)
	{
		T* val = (T*)malloc(length * sizeof(T));
		memset(val, 0, length * sizeof(T));
		val[0] = start;

		va_list ap;
		va_start(ap, start);
		for (int i = 0; i < length - 1; i++)
		{
			T temp;
			GET_VA_ARG(temp, ap);
			val[i + 1] = temp;
		}
		va_end(ap);

		return val;
	}

	template<typename T>
	T* GET_PARAMETERS(int length, T start, va_list ap)
	{
		T* val = (T*)malloc(length * sizeof(T));
		memset(val, 0, length * sizeof(T));
		val[0] = start;

		for (int i = 0; i < length - 1; i++)
		{
			T temp;
			GET_VA_ARG(temp, ap);
			val[i + 1] = temp;
		}

		return val;
	}
}