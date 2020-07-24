#pragma once

#include "Algebra/Vector/Vector.h"

namespace math
{
	struct Matrix44;
	struct Vector3;
	/**
	*	四元数
	*	p = w + x * vx  + y * vy + z * vz;
	*	p = (w, v), 角度，方向向量
	*	向量：v = (x, y, z)
	*   向量v的方向：vn = (vx, vy, vz)
	*************************************************************
	*	虚数的模代表向量的长度，虚数的加减可以代表向量的加减。
	*	虚数的乘法为，当前方位的虚数乘以变量量代表的虚数，得到结果虚数表示该方位变换后的方位。
	*	p(x,yi)
	*	q(cosθ, i*sinθ)
	*	p'= p * q = ( xcosθ - ysinθ, (xsinθ + ycosθ)i );
	*	和p(x,y)乘以旋转矩阵( cosθ, sinθ
	*	-sinθ, cosθ) 结果是( xcosθ - ysinθ, xsinθ + ycosθ)结果是一样的。
	*	但是三维中的虚数却要用四元数来表示，且四元数实现旋转不是p*q,而是p*q*p-1形式实现和矩阵旋转等同的变换。
	*************************************************************
	*	四元数表示三维空间中的虚数，由william hamilton于1843年在去皇家爱尔兰学院路上时意识到
	*	将复数从2D空间拓展到3D空间不是用一个实部和两个虚部，而是一个实部和三个虚部，于是他将四元数的定义刻在Broome桥上。
	*	四元数的定义：
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
		CREATE_AXIS(W, 0);
		CREATE_AXIS(X, 1);
		CREATE_AXIS(Y, 2);
		CREATE_AXIS(Z, 3);
	public:
		/**
		*	标准化,单位四元数
		*	数学上(1,0,0,0)为单位四元数，
		*	几何上(1,0,0,0)和(-1,0,0,0)都可以作为单位四元数因为角位移都一样，
		*	一般用(1,0,0,0)表示为单位四元数
		*/
		static Quaternion identity();
		/**
		*	负四元数
		*/
		Quaternion negative();
		/**
		*	共轭
		*	q*= (w, -x, -y, -z)相反的轴旋转相同的量，也可以为q*= (-w, x, y, z)相同的轴旋转相反的量
		*	一般用(w, -x, -y, -z)表示为单位四元数
		*/
		Quaternion conjugate();
		/**
		*	四元数的逆
		*/
		Quaternion inverse();
		/**
		*	模
		*/
		float getMagnitude();
		/**
		*	单位化
		*/
		Quaternion normalize();
	public:
		/**
		*	相等
		*/
		virtual Quaternion operator*(const Quaternion& quaternion);
		/**
		*	转换为矩阵
		*/
		operator Matrix44();
	public:
		/**
		*	绕轴vector旋转angle得到的四元数
		*/
		static Quaternion rotate(const Vector3& vector, float angle);
		/**
		*	绕x轴旋转roll度，y轴旋转pitch度，z轴旋转yaw度，形成的四元素
		*/
		static Quaternion rotate(float roll, float pitch, float yaw);
		/**
		*	绕z轴旋转yaw度，y轴旋转pitch度，x轴旋转roll度，形成的四元素
		*/
		static Quaternion rotate(const Vector3& rotation);
		/**
		*	绕轴vector旋转四元数quaternion得到的向量
		*/
		static Vector3 rotate(const Vector3& vector, const Quaternion& quaternion);
		/**
		*	先旋转q0，再旋转q1，标准乘法
		*/
		static Quaternion rotateBy(const Quaternion& q0, const Quaternion& q1);
		/**
		*	通过四元组，求得旋转角
		*/
		static Vector3 euler(const Quaternion& quaternion);
		/**
		*	通过四元组，求得矩阵
		*/
		static Matrix44 mat(const Quaternion& quaternion);
	};
}