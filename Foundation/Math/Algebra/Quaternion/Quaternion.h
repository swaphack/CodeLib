#pragma once

#include "Algebra/Vector/Vector.h"

namespace math
{
	struct Matrix4x4;
	struct Vector3;
	/**
	*	��Ԫ��
	*	p = w + x * vx  + y * vy + z * vz;
	*	p = (w, v), �Ƕȣ���������
	*	������v = (x, y, z)
	*   ����v�ķ���vn = (vx, vy, vz)
	*************************************************************
	*	������ģ���������ĳ��ȣ������ļӼ����Դ��������ļӼ���
	*	�����ĳ˷�Ϊ����ǰ��λ���������Ա�����������������õ����������ʾ�÷�λ�任��ķ�λ��
	*	p(x,yi)
	*	q(cos��, i*sin��)
	*	p'= p * q = ( xcos�� - ysin��, (xsin�� + ycos��)i );
	*	��p(x,y)������ת����( cos��, sin��
	*	-sin��, cos��) �����( xcos�� - ysin��, xsin�� + ycos��)�����һ���ġ�
	*	������ά�е�����ȴҪ����Ԫ������ʾ������Ԫ��ʵ����ת����p*q,����p*q*p-1��ʽʵ�ֺ;�����ת��ͬ�ı任��
	*************************************************************
	*	��Ԫ����ʾ��ά�ռ��е���������william hamilton��1843����ȥ�ʼҰ�����ѧԺ·��ʱ��ʶ��
	*	��������2D�ռ���չ��3D�ռ䲻����һ��ʵ���������鲿������һ��ʵ���������鲿������������Ԫ���Ķ������Broome���ϡ�
	*	��Ԫ���Ķ��壺
	*	(w,x,y,z) = w + xi + yj + zk;
	*	i*i = j*j = k*k = -1;
	*	ij = k, ji= -k;
	*	jk = i, kj = -i;
	*	ki = j, ik= -j;
	*/
	struct Quaternion : public Vector<float, 4>
	{
	public:
		Quaternion();
		Quaternion(const Quaternion& quaternion);
		Quaternion(float w, float x, float y, float z);
		Quaternion(float w, const Vector3& vector);
		virtual ~Quaternion();
	public:
		CREATE_INDEX_VALUE(W, 0, float);
		CREATE_INDEX_VALUE(X, 1, float);
		CREATE_INDEX_VALUE(Y, 2, float);
		CREATE_INDEX_VALUE(Z, 3, float);
	public:
		/**
		*	��׼��,��λ��Ԫ��
		*	��ѧ��(1,0,0,0)Ϊ��λ��Ԫ����
		*	������(1,0,0,0)��(-1,0,0,0)��������Ϊ��λ��Ԫ����Ϊ��λ�ƶ�һ����
		*	һ����(1,0,0,0)��ʾΪ��λ��Ԫ��
		*/
		static Quaternion identity();
		/**
		*	����Ԫ��
		*/
		Quaternion negative() const;
		/**
		*	����
		*	q*= (w, -x, -y, -z)�෴������ת��ͬ������Ҳ����Ϊq*= (-w, x, y, z)��ͬ������ת�෴����
		*	һ����(w, -x, -y, -z)��ʾΪ��λ��Ԫ��
		*/
		Quaternion conjugate() const;
		/**
		*	��Ԫ������
		*/
		Quaternion inverse()const;
		/**
		*	ģ
		*/
		float getMagnitude() const;
		/**
		*	ģ��ƽ��
		*/
		float getSqrMagnitude() const;
		/**
		*	��λ��
		*/
		void normalize();
		/**
		*	��ȡ�Ƕ�
		*/
		math::Vector3 eulerAngle() const;
		/**
		*	��ȡ�鲿ֵ
		*/
		math::Vector3 vector() const;
		/**
		*	�鲿��ʵ���ļн�
		*/
		float radian() const;
	public:
		/**
		*	���
		*/
		Quaternion operator*(const Quaternion& quaternion) const;
		/**
		*	��ֵ
		*/
		Quaternion operator-(const Quaternion& quaternion) const;
		/**
		*	����
		*/
		Quaternion operator*(float k) const;
		/**
		*	ת��Ϊ����
		*/
		operator Matrix4x4() const;
	public:
		/**
		*	����vector��תangle�õ�����Ԫ��
		*/
		static Quaternion rotate(const Vector3& vector, float angle);
		/**
		*	��x����תroll�ȣ�y����תpitch�ȣ�z����תyaw�ȣ��γɵ���Ԫ��
		*/
		static Quaternion rotate(float roll, float pitch, float yaw);
		/**
		*	��z����תyaw�ȣ�y����תpitch�ȣ�x����תroll�ȣ��γɵ���Ԫ��
		*/
		static Quaternion rotate(const Vector3& rotation);
		/**
		*	����vector��ת��Ԫ��quaternion�õ�������
		*/
		static Vector3 rotate(const Vector3& vector, const Quaternion& quaternion);
		/**
		*	����תq0������תq1����׼�˷�
		*/
		static Quaternion rotateBy(const Quaternion& q0, const Quaternion& q1);
		/**
		*	ͨ����Ԫ�飬�����ת��
		*/
		static Vector3 euler(const Quaternion& quaternion);
		/**
		*	ͨ����Ԫ�飬��þ���
		*/
		static Matrix4x4 mat(const Quaternion& quaternion);
		/**
		*	��׼��
		*/
		static Quaternion normalize(const Quaternion& quaternion);
		/**
		*	���
		*/
		static float dot(const Quaternion& src, const Quaternion& dest);
	};

	static inline Quaternion operator*(float k, const Quaternion& src)
	{
		return src * k;
	}
}