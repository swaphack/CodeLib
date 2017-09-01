#pragma once

struct Vector3 
{
public:
	float x = 0;
	float y = 0;
	float z = 0;
public:
	Vector3();
	Vector3(float x, float y);
	Vector3(float x, float y, float z);
public:
	// 距离
	float Distance(const Vector3& target);
	// 长度
	float Length();
	// 向量
	Vector3 operator-(const Vector3& target);
	Vector3 operator+(const Vector3& target);
	// 向量
	Vector3 operator*(float k);
};