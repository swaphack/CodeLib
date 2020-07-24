#pragma once


#include "Light.h"

namespace render
{
	/**
	*	���Դ
	*/
	class PointLight : public Light
	{
	public:
		PointLight();
		virtual ~PointLight();
	public:
		virtual void draw();
	public:

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
		// ����˥����������޹�
		float _constantAttenuation;
		// ����������˥��
		float _linearAttenuation;
		// ��������κ���˥��
		float _quadraticAttenuation;

		// ����
		float _lightDirection[3];
	};

#define CTREATE_POINT_LIGHT(index) \
	class PointLight##index : public PointLight \
	{ \
	public: \
	virtual LightName getLightName() { return LightName::LIGHT##index; } \
	};

	CTREATE_POINT_LIGHT(0);
	CTREATE_POINT_LIGHT(1);
	CTREATE_POINT_LIGHT(2);
	CTREATE_POINT_LIGHT(3);
	CTREATE_POINT_LIGHT(4);
	CTREATE_POINT_LIGHT(5);
	CTREATE_POINT_LIGHT(6);
	CTREATE_POINT_LIGHT(7);
}