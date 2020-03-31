#pragma once

#include "system.h"
#include "mathlib.h"
#include "Graphic/GLAPI/macros.h"

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
		// ����
		math::Vector3 normal;

		TextureVertex()
		{
			normal = math::Vector3(0, 0, 1);
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

	public:
		void setNormal(const math::Vector3& normal)
		{
			leftDown.normal = normal;
			rightDown.normal = normal;
			rightUp.normal = normal;
			leftUp.normal = normal;
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
		BlendingFactorSrc src = BlendingFactorSrc::SRC_ALPHA;
		BlendingFactorDest dest = BlendingFactorDest::ONE_MINUS_SRC_ALPHA;

		BlendParam()
		{}

		BlendParam(BlendingFactorSrc src, BlendingFactorDest dest) :src(src), dest(dest)
		{}

		BlendParam& operator=(const BlendParam& blend)
		{
			src = blend.src;
			dest = blend.dest;

			return *this;
		}
	};
}