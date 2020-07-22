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
	public:
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
	};

#define CTREATE_SPOT_LIGHT(index) \
	class SpotLight##index : public SpotLight \
	{ \
	public: \
	virtual LightName getLightName() { return LightName::LIGHT##index; } \
	};

	CTREATE_SPOT_LIGHT(0);
	CTREATE_SPOT_LIGHT(1);
	CTREATE_SPOT_LIGHT(2);
	CTREATE_SPOT_LIGHT(3);
	CTREATE_SPOT_LIGHT(4);
	CTREATE_SPOT_LIGHT(5);
	CTREATE_SPOT_LIGHT(6);
	CTREATE_SPOT_LIGHT(7);
}