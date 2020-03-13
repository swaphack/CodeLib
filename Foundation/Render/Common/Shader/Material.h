#pragma once

#include "system.h"

namespace render
{
	// 材质
	class Material : public sys::Object
	{
	public:
		Material();
		virtual ~Material();
	public:
		// 恢复默认
		static void applyDefault();
		// 应用
		void apply();
		// 环境光
		void setAmbientByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		// 环境光
		void setAmbient(float red, float green, float blue, float alpha = 1);

		const float* getAmbient() const;

		// 漫射光
		void setDiffuseByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		// 漫射光
		void setDiffuse(float red, float green, float blue, float alpha = 1);

		const float* getDiffuse() const;

		// 反射光
		void setSpecularByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		// 反射光
		void setSpecular(float red, float green, float blue, float alpha = 1);
		const float* getSpecular() const;

		// 镜面指数
		void setShiness(float value);
		float getShiness() const;

		// 辐射光颜色
		void setEmisiionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
		// 反射光
		void setEmisiion(float red, float green, float blue, float alpha = 1);
		const float* getEmisiion() const;

		Material& operator = (const Material& value);
	protected:
		// 环境光
		float _matrialAmbient[4];
		// 漫射光
		float _matrialDiffuse[4];
		// 反射光
		float _matrialSpecular[4];
		// 镜面指数
		float _matrialShiness;
		// 辐射光颜色
		float _matrialEmission[4];

	};
}