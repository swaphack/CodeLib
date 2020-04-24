#pragma once
#include "macros.h"
#include "mathlib.h"
namespace render
{
	/**
	*	材质
	*/
	class GLMaterial
	{
	public:
		static void getMaterial(GetMaterialFace face, MaterialParameter parameter, float* value);

		static void setMaterial(FaceType face, MaterialParameter type, const float* value);

		static void setMaterialAmbient(FaceType face, const float* value);
		static void setMaterialAmbient(FaceType face, const math::Vector4& value);

		static void setMaterialDiffuse(FaceType face, const float* value);
		static void setMaterialDiffuse(FaceType face, const math::Vector4&  value);

		static void setMaterialSpecular(FaceType face, const float* value);
		static void setMaterialSpecular(FaceType face, const math::Vector4& value);

		static void setMaterialEmission(FaceType face, const float* value);
		static void setMaterialEmission(FaceType face, const math::Vector4& value);

		static void setMaterialShininess(FaceType face, const float* value);
		static void setMaterialShininess(FaceType face, float value);

		static void setMaterialAmbientAndDiffuse(FaceType face, const float* value);
		static void setMaterialAmbientAndDiffuse(FaceType face, const math::Vector4& value);

		static void setMaterialColorIndexes(FaceType face, const float* value);
		static void setMaterialColorIndexes(FaceType face, const math::Vector3& value);
	public:
		/**
		*	材质颜色可通过设置
		*	glEnable(GL_COLOR_MATERIAL )， glDisable
		*/
		static void setColorMaterial(FaceType face, ColorMaterialParameter type);
	};
}