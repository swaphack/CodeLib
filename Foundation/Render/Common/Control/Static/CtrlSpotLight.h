#pragma once

#include "CtrlLight.h"

namespace render
{
	// �⣬�۹��
	class CtrlSpotLight : public CtrlLight
	{
	public:
		CtrlSpotLight();
		virtual ~CtrlSpotLight();
	public:
		virtual void draw();

		// �۹�ǿ��
		void setExponent(float value);
		float getExponent();

		// ���ǽǶ�
		void setCutOff(float value);
		float getCutOff();

		// ����
		void setDirection(float x, float y, float z);
		const float* getDirection();

		// ����˥����������޹�
		void setConstantAttenuation(float value);
		float getConstantAttenuation();

		// ����������˥��
		void setLinearAttenuation(float value);
		float getLinearAttenuation();

		// ��������κ���˥��
		void setQuadraticAttenuation(float value);
		float getQuadraticAttenuation();
	protected:
		// �۹�ǿ��
		float _spotExponent;
		// ���ǽǶ�
		float _spotCutOff;
		// ����
		float _spotDirection[3];
		// ����˥����������޹�
		float _constantAttenuation;
		// ����������˥��
		float _linearAttenuation;
		// ��������κ���˥��
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