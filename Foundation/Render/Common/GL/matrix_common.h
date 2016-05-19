#pragma once

#include "system.h"
#include <cmath>

// 矩阵
namespace render
{
	/*
	{
	1.0f, 0.0f, 0.0f, 0.0f,		// x
	0.0f, 1.0f, 0.0f, 0.0f,		// y
	0.0f, 0.0f, 1.0f, 0.0f,		// z
	0.0f, 0.0f, 0.0f, 1.0f,		// 平移
	}
	*/
	// 节点的基础数据
	struct Matrix
	{
		// 坐标
		sys::Vector Position;
		// 缩放
		sys::Vector Scale;
		// 旋转
		sys::Vector Rotation;

		float matrix[16];
	public:
		Matrix();
		~Matrix();
	public:
		// 重置矩阵
		void reset();
		// 生成矩阵
		void make();
	};
}