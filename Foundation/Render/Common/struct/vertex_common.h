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
		sys::Color4B color;
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

		void setLeftDownColor(const sys::Color4F& color);
		void setRightDownColor(const sys::Color4F& color);
		void setRightUpColor(const sys::Color4F& color);
		void setLeftUpColor(const sys::Color4F& color);

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
}
