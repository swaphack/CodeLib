#pragma once

#include "system.h"
#include "mathlib.h"
#include "Graphic/GLAPI/macros.h"
#include "enum_common.h"

// ����
namespace render
{
	// ������Ϣ
	struct Vertex
	{
		// ��������
		math::Vector3 point;
		// ������������
		math::Vector3 coords;
		// ������ɫ
		phy::Color4B color;
		// ����
		math::Vector3 normal;

		Vertex();
	};
	// ���ζ�����Ϣ
	struct RectVertex
	{
		float vertices[12];
		float colors[16];
		float uvs[8];
		uint32_t indices[6];
	public:
		RectVertex();
	public:
		void setLeftDownPoint(const math::Vector3& point);
		void setRightDownPoint(const math::Vector3& point);
		void setRightUpPoint(const math::Vector3& point);
		void setLeftUpPoint(const math::Vector3& point);

		void setLeftDownColor(const phy::Color4F& color);
		void setRightDownColor(const phy::Color4F& color);
		void setRightUpColor(const phy::Color4F& color);
		void setLeftUpColor(const phy::Color4F& color);

		void setLeftDownUV(const math::Vector2& point);
		void setRightDownUV(const math::Vector2& point);
		void setRightUpUV(const math::Vector2& point);
		void setLeftUpUV(const math::Vector2& point);
	};

	// �����嶥����Ϣ
	struct CubeVertex
	{
	public:
		RectVertex left;
		RectVertex right;

		RectVertex front;
		RectVertex back;

		RectVertex top;
		RectVertex bottom;
	public:
		CubeVertex();
	public:
		void setFrontLeftDownPosition(const math::Vector3& point);
		void setFrontRightDownPosition(const math::Vector3& point);
		void setFrontRightUpPosition(const math::Vector3& point);
		void setFrontLeftUpPosition(const math::Vector3& point);

		void setBackLeftDownPosition(const math::Vector3& point);
		void setBackRightDownPosition(const math::Vector3& point);
		void setBackRightUpPosition(const math::Vector3& point);
		void setBackLeftUpPosition(const math::Vector3& point);

		const RectVertex* getFaceVertex(CubeFace face) const;

		const RectVertex* getCubMapFaceVertex(CubeFace face) const;
	};

	// 9���� ���õ���Ϣ
	struct SimpleScale9Vertex
	{
		float vertices[48];
		float colors[64];
		float uvs[32];
		uint32_t indices[54];
	public:
		SimpleScale9Vertex();
	public:
		// �ӵײ���ʼ����
		void setLayerPoints0(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3);
		void setLayerPoints1(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3);
		void setLayerPoints2(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3);
		void setLayerPoints3(const math::Vector3& p0, const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3);
		// �ӵײ���ʼ����
		void setLayerUVs0(const math::Vector2& p0, const math::Vector2& p1, const math::Vector2& p2, const math::Vector2& p3);
		void setLayerUVs1(const math::Vector2& p0, const math::Vector2& p1, const math::Vector2& p2, const math::Vector2& p3);
		void setLayerUVs2(const math::Vector2& p0, const math::Vector2& p1, const math::Vector2& p2, const math::Vector2& p3);
		void setLayerUVs3(const math::Vector2& p0, const math::Vector2& p1, const math::Vector2& p2, const math::Vector2& p3);
	};
}
