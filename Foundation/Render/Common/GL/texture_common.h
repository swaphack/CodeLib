#pragma once

#include "system.h"
#include "mathlib.h"

// ����
namespace render
{
	// ��������
	struct TextureVertex
	{
		// ��������
		math::Vector3 point;
		// ������������
		math::Vector3 coords;
		// ������ɫ
		sys::Color4B color;

		TextureVertex()
		{

		}
	};

	// �������� ��ʱ�뷽��
	struct TextureRect
	{
		// ���½�
		TextureVertex leftDown;
		// ���½�
		TextureVertex rightDown;
		// ���Ͻ�
		TextureVertex rightUp;
		// ���Ͻ�
		TextureVertex leftUp;

		TextureRect()
		{
			leftDown.coords = math::Vector3(0.0f, 0.0f, 0.0f);
			rightDown.coords = math::Vector3(1.0f, 0.0f, 0.0f);
			rightUp.coords = math::Vector3(1.0f, 1.0f, 0.0f);
			leftUp.coords = math::Vector3(0.0f, 1.0f, 0.0f);
		}
	};

	// ����������
	struct TextureCube
	{
		// ǰ��
		TextureRect front;
		// ����
		TextureRect back;
		// ����
		TextureRect left;
		// ����
		TextureRect right;
		// ����
		TextureRect top;
		// �ײ�
		TextureRect bottom;

		TextureCube()
		{
		}
	};

	// ��ϲ���
	struct BlendParam
	{
		int src;
		int dest;

		BlendParam() :src(0), dest(0)
		{}

		BlendParam(int src, int dest) :src(src), dest(dest)
		{}

		BlendParam& operator=(const BlendParam& blend)
		{
			src = blend.src;
			dest = blend.dest;

			return *this;
		}
	};
}