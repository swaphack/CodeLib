#pragma once

#include "mathlib.h"
#include "macros.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	/**
	*	���㴦��
	*/
	class GLVertex
	{
	public:// ģʽ
		static void beginMode(ShapeMode mode);
		static void endMode();
	public:// ����
		static void setVertex(float x, float y, float z);
		static void setVertex(const math::Vector3& value);
	public:// ����
		static void setNormal(float x, float y, float z);
		static void setNormal(const math::Vector3& value);
	public:// ��ɫ
		static void setColor(float r, float g, float b, float a = 1);
		static void setColor(float* rgba);
		static void setColor(const phy::Color3F& value, float opacity = 1);
		static void setColor(const phy::Color4F& value, float opacity = 1);
		static void setColor(const phy::Color3B& value, uint8_t opacity = 255);
		static void setColor(const phy::Color4B& value, uint8_t opacity = 255);
	public:// ��ɫ����
		static void setIndex(int index);
	public:// ����
		static void setTexCoord1D(float s);
		static void setTexCoord2D(float s, float t);
		static void setTexCoord2D(const math::Vector2& value);
		static void setTexCoord3D(float s, float t, float r);
		static void setTexCoord3D(const math::Vector3& value);
	
	public:// ���ñ�Ե�༭
		static void setEdgeFlag(bool flag);
		
	};
}