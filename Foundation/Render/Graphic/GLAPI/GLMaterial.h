#pragma once
#include "macros.h"
#include "mathlib.h"
namespace render
{
	/**
	*	����
	*/
	class GLMaterial
	{
	public:
		static void setMaterial(MaterialFace face, MaterialParameter type, const float* value);

		static void setMaterialAmbient(MaterialFace face, const float* value);
		static void setMaterialAmbient(MaterialFace face, const math::Vector4& value);

		static void setMaterialDiffuse(MaterialFace face, const float* value);
		static void setMaterialDiffuse(MaterialFace face, const math::Vector4&  value);

		static void setMaterialSpecular(MaterialFace face, const float* value);
		static void setMaterialSpecular(MaterialFace face, const math::Vector4& value);

		static void setMaterialEmission(MaterialFace face, const float* value);
		static void setMaterialEmission(MaterialFace face, const math::Vector4& value);

		static void setMaterialShininess(MaterialFace face, const float* value);
		static void setMaterialShininess(MaterialFace face, float value);

		static void setMaterialAmbientAndDiffuse(MaterialFace face, const float* value);
		static void setMaterialAmbientAndDiffuse(MaterialFace face, const math::Vector4& value);

		static void setMaterialColorIndexes(MaterialFace face, const float* value);
		static void setMaterialColorIndexes(MaterialFace face, const math::Vector3& value);
	public:
		/**
		*	������ɫ��ͨ������
		*	glEnable(GL_COLOR_MATERIAL )�� glDisable
		*/
		static void setColorMaterial(ColorMaterialFace face, ColorMaterialParameter type);
	};
}