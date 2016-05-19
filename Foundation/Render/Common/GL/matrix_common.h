#pragma once

#include "system.h"
#include <cmath>

// ����
namespace render
{
	/*
	{
	1.0f, 0.0f, 0.0f, 0.0f,		// x
	0.0f, 1.0f, 0.0f, 0.0f,		// y
	0.0f, 0.0f, 1.0f, 0.0f,		// z
	0.0f, 0.0f, 0.0f, 1.0f,		// ƽ��
	}
	*/
	// �ڵ�Ļ�������
	struct Matrix
	{
		// ����
		sys::Vector Position;
		// ����
		sys::Vector Scale;
		// ��ת
		sys::Vector Rotation;

		float matrix[16];
	public:
		Matrix();
		~Matrix();
	public:
		// ���þ���
		void reset();
		// ���ɾ���
		void make();
	};
}