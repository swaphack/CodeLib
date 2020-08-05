#pragma once

#include "PointLight.h"

namespace render
{
	// 光，聚光灯
	class SpotLight : public PointLight
	{
	public:
		SpotLight();
		virtual ~SpotLight();
	public:
		virtual void draw();

		virtual bool init();
	public:
		// 朝向
		const float* getDirection();

		// 聚光强度
		void setExponent(float value);
		float getExponent();

		// 覆盖范围
		void setCutOff(float value);
		float getCutOff();
	protected:
		// 聚光强度
		float _spotExponent;
		// 覆盖范围
		float _spotCutOff;
		// 朝向
		float _lightDirection[3];
	};
}