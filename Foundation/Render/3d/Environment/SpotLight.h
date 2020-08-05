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

		virtual bool init();
	public:
		// ����
		const float* getDirection();

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
		// ����
		float _lightDirection[3];
	};
}