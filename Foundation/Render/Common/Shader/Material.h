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
		void setAmbient(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getAmbient();

		// 漫射光
		void setDiffuse(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getDiffuse();

		// 反射光
		void setSpecular(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getSpecular();

		// 镜面指数
		void setShiness(float value);
		float getShiness();

		// 辐射光颜色
		void setEmisiion(uchar red, uchar green, uchar blue, uchar alpha);
		const float* getEmisiion();
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