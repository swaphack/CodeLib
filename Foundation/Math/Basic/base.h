#pragma once

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
#define ADJUST_DURATION_VALUE_RANGE(a, min, max, range)\
		while (a < min) a+= range; while (a > max) a-=range;
	/**
	*	�ж����������������ķ�Χ���Ƿ����
	*/
#define APPROXIMATELY(a, b) (fabs((a) - (b)) <= EPSILON)

	/**
	*	�������Ա
	*/
#define CREATE_CLASS_MEMBER_WITH_DEFAULT(Type, Name, DefaultValue) \
public:\
	Type get##Name() const { return _##Name; }\
	void set##Name(Type val) { _##Name = val; } \
private: Type _##Name = DefaultValue;

	/**
	*	�������Ա
	*/
#define CREATE_CLASS_MEMBER(Type, Name) \
public:\
	Type get##Name() const { return _##Name; }\
	void set##Name(Type val) { _##Name = val; } \
private: Type _##Name;

	/**
	*	�������Ա
	*/
#define CREATE_CLASS_VECTOR_MEMBER(Type, Name, VectorName, Index) \
public:\
	Type get##Name() const { return (Type)VectorName[Index]; }\
	void set##Name(Type val) { VectorName[Index] = val; } \

}