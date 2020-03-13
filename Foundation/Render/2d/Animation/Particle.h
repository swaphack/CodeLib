#pragma once

#include "macros.h"

namespace render
{
	// ����
	class ParticleProtocol
	{
	public:
		ParticleProtocol();
		virtual ~ParticleProtocol();
	public:
		// ���ü��ٶ�
		void setSpeedAcceleration(float x, float y, float z);
		// ��ȡ���ٶ�
		math::Vector3 getSpeedAccelertaion();
		// ���ýǶȱ任�ٶ�
		void setAngleAcceleration(float x, float y, float z);
		// ��ȡ�Ƕȱ任�ٶ�
		math::Vector3 getAngleAcceleration();
		// �������ű任�ٶ�
		void setScaleAcceleration(float x, float y, float z);
		// ��ȡ���ű任�ٶ�
		math::Vector3 getScaleAcceleration();
		// ����ɫ�ʽ����ٶ�
		void setColorAcceleration(float red, float green, float blue, float alpha);
		// ��ȡɫ�ʽ����ٶ�
		sys::Color4F getColorAcceleration();
		// ��������
		void setLifeTime(float time);
		// ��ȡ����
		float getLifeTime();
	protected:
		// ���ٶ�
		math::Vector3 _speedAcceleration;
		// �Ƕȱ任�ٶ�
		math::Vector3 _angleAcceleration;
		// ���ű任�ٶ�
		math::Vector3 _scaleAcceleration;
		// ɫ���ٶ�
		sys::Color4F _colorAcceleration;
		// ����
		float _lifeTime;
	};
}