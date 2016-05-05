#pragma once

#include "system.h"

// ����
namespace render
{
	// ��������
	struct TextureVertex
	{
		// ��������
		sys::Vector point;
		// ������������
		sys::Vector coords;
		// ������ɫ
		sys::Color4B blend;

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
			leftDown.coords = sys::Vector(0.0f, 0.0f, 0.0f);
			rightDown.coords = sys::Vector(1.0f, 0.0f, 0.0f);
			rightUp.coords = sys::Vector(1.0f, 1.0f, 0.0f);
			leftUp.coords = sys::Vector(0.0f, 1.0f, 0.0f);
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
}