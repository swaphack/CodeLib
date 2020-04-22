#pragma once

#include "system.h"
#include "mathlib.h"
#include "Graphic/GLAPI/macros.h"

// 纹理
namespace render
{
	// 纹理坐标
	struct TextureVertex
	{
		// 顶点坐标
		math::Vector3 point;
		// 顶点纹理坐标
		math::Vector3 coords;
		// 顶点颜色
		sys::Color4B color;
		// 法线
		math::Vector3 normal;

		TextureVertex();
	};

	// 混合参数
	struct BlendParam
	{
		BlendingFactorSrc src = BlendingFactorSrc::ONE;
		BlendingFactorDest dest = BlendingFactorDest::ONE_MINUS_SRC_ALPHA;

		BlendParam();

		BlendParam(BlendingFactorSrc src, BlendingFactorDest dest);

		BlendParam& operator=(const BlendParam& blend);
	};

	struct TextureRectVertex
	{
		float vertices[12] ;
		float colors[16];
		float uvs[8];
		uint16_t indices[6];
	public:
		TextureRectVertex();
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

		void flipX();
		void flipY();

	};

	// 立方体纹理
	struct TextureCubeVertex
	{
		float vertices[24];
		float colors[32];
		float uvs[16];
		uint32_t indices[36];
		float normals[24];
	public:
		TextureCubeVertex();
	public:
		void setFrontLeftDownPoint(const math::Vector3& point);
		void setFrontRightDownPoint(const math::Vector3& point);
		void setFrontRightUpPoint(const math::Vector3& point);
		void setFrontLeftUpPoint(const math::Vector3& point);

		void setBackLeftDownPoint(const math::Vector3& point);
		void setBackRightDownPoint(const math::Vector3& point);
		void setBackRightUpPoint(const math::Vector3& point);
		void setBackLeftUpPoint(const math::Vector3& point);

		void setFrontLeftDownColor(const sys::Color4B& color);
		void setFrontRightDownColor(const sys::Color4B& color);
		void setFrontRightUpColor(const sys::Color4B& color);
		void setFrontLeftUpColor(const sys::Color4B& color);

		void setBackLeftDownColor(const sys::Color4B& color);
		void setBackRightDownColor(const sys::Color4B& color);
		void setBackRightUpColor(const sys::Color4B& color);
		void setBackLeftUpColor(const sys::Color4B& color);
	};
}
