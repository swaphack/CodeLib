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
	};
}