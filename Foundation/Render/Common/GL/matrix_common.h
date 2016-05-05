#pragma once

#include "system.h"

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

		Matrix()
		{
			this->reset();
		}

		void reset()
		{
			Position = sys::Vector(0, 0, 0);
			Scale = sys::Vector(1, 1, 1);
			Rotation = sys::Vector(0, 0, 0);

			matrix[0] = 1.0f;
			matrix[1] = 0.0f;
			matrix[2] = 0.0f;
			matrix[3] = 0.0f;

			matrix[4] = 0.0f;
			matrix[5] = 1.0f;
			matrix[6] = 0.0f;
			matrix[7] = 0.0f;

			matrix[8] = 0.0f;
			matrix[9] = 0.0f;
			matrix[10] = 1.0f;
			matrix[11] = 0.0f;

			matrix[12] = 0.0f;
			matrix[13] = 0.0f;
			matrix[14] = 0.0f;
			matrix[15] = 1.0f;
		}

		void initNormalNode()
		{
			matrix[0] = Scale.x;
			matrix[1] = 0.0f;
			matrix[2] = 0.0f;
			matrix[3] = Rotation.x;

			matrix[4] = 0.0f;
			matrix[5] = Scale.y;
			matrix[6] = 0.0f;
			matrix[7] = Rotation.y;

			matrix[8] = 0.0f;
			matrix[9] = 0.0f;
			matrix[10] = Scale.z;
			matrix[11] = Rotation.z;

			matrix[12] = Position.x;
			matrix[13] = Position.y;
			matrix[14] = Position.z;
			matrix[15] = 1.0f;
		}

		
		void initDrawNode()
		{
			matrix[0] = Scale.x;
			matrix[1] = 0.0f;
			matrix[2] = 0.0f;
			matrix[3] = Rotation.x;

			matrix[4] = 0.0f;
			matrix[5] = Scale.y;
			matrix[6] = 0.0f;
			matrix[7] = Rotation.y;

			matrix[8] = 0.0f;
			matrix[9] = 0.0f;
			matrix[10] = Scale.z;
			matrix[11] = Rotation.z;

			matrix[12] = 0.0f;
			matrix[13] = 0.0f;
			matrix[14] = 0.0f;
			matrix[15] = 1.0f;
		}
		
	};
}