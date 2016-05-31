#pragma once

#include "../Data/Target.h"

namespace slg
{
	// ��ͼ�ϵĸ���
	class  IGrid
	{
	public:
		virtual ~IGrid() {}
	public:
		// ����x��λ��
		virtual int getPositionX() = 0;
		// ����y��λ��
		virtual int getPositionY() = 0;
		// ���ӿ��
		virtual int getWidth() = 0;
		// ���Ӹ߶�
		virtual int getHeight() = 0;
		// Ŀ��
		virtual Target* getTarget() = 0;
	};
}