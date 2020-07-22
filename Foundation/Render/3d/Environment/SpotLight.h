#pragma once

#include "PointLight.h"

namespace render
{
	// �⣬�۹��
	class SpotLight : public PointLight
	{
	public:
		SpotLight();
		virtual ~SpotLight();
	public:
		virtual void draw();
	public:
		// �۹�ǿ��
		void setExponent(float value);
		float getExponent();

		// ���Ƿ�Χ
		void setCutOff(float value);
		float getCutOff();
	protected:
		// �۹�ǿ��
		float _spotExponent;
		// ���Ƿ�Χ
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