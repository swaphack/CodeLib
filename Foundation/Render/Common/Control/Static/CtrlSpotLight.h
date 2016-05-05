#pragma once

#include "CtrlLight.h"

namespace render
{
	// 光，聚光灯
	class CtrlSpotLight : public CtrlLight
	{
	public:
		CtrlSpotLight();
		virtual ~CtrlSpotLight();
	public:
		virtual void draw();

		// 聚光强度
		void setExponent(float value);
		float getExponent();

		// 覆盖角度
		void setCutOff(float value);
		float getCutOff();

		// 朝向
		void setDirection(float x, float y, float z);
		const float* getDirection();

		// 常熟衰减，与距离无关
		void setConstantAttenuation(float value);
		float getConstantAttenuation();

		// 按距离线性衰减
		void setLinearAttenuation(float value);
		float getLinearAttenuation();

		// 按距离二次函数衰减
		void setQuadraticAttenuation(float value);
		float getQuadraticAttenuation();
	protected:
		// 聚光强度
		float _spotExponent;
		// 覆盖角度
		float _spotCutOff;
		// 朝向
		float _spotDirection[3];
		// 常熟衰减，与距离无关
		float _constantAttenuation;
		// 按距离线性衰减
		float _linearAttenuation;
		// 按距离二次函数衰减
		float _quadraticAttenuation;
	};

#define CTREATE_SPOT_LIGHT_CLASS_0(index) \
	class CtrlSpotLight##index : public CtrlSpotLight \
	{ \
	public: \
	virtual LightIndex getLightIndex() { return ELI_LIGHT##index; } \
	};

#define CTREATE_SPOT_LIGHT_CLASS_1(index) \
	class CtrlSpotLight##index : public CtrlSpotLight \
	{ \
	public: \
	CtrlSpotLight##index() \
	{ \
	_lightDiffuse[0] = 0.0f; \
	_lightDiffuse[1] = 0.0f; \
	_lightDiffuse[2] = 0.0f; \
	_lightDiffuse[3] = 1.0f; \
	_lightSpecular[0] = 0.0f; \
	_lightSpecular[1] = 0.0f; \
	_lightSpecular[2] = 0.0f; \
	_lightSpecular[3] = 1.0f; \
	} \
	virtual LightIndex getLightIndex() { return ELI_LIGHT##index; } \
	};

	CTREATE_SPOT_LIGHT_CLASS_0(0);
	CTREATE_SPOT_LIGHT_CLASS_1(1);
	CTREATE_SPOT_LIGHT_CLASS_1(2);
	CTREATE_SPOT_LIGHT_CLASS_1(3);
	CTREATE_SPOT_LIGHT_CLASS_1(4);
	CTREATE_SPOT_LIGHT_CLASS_1(5);
	CTREATE_SPOT_LIGHT_CLASS_1(6);
	CTREATE_SPOT_LIGHT_CLASS_1(7);
}