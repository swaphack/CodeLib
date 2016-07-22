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
		sys::Vector getSpeedAccelertaion();
		// ���ýǶȱ任�ٶ�
		void setAngleAcceleration(float x, float y, float z);
		// ��ȡ�Ƕȱ任�ٶ�
		sys::Vector getAngleAcceleration();
		// �������ű任�ٶ�
		void setScaleAcceleration(float x, float y, float z);
		// ��ȡ���ű任�ٶ�
		sys::Vector getScaleAcceleration();
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
		sys::Vector _speedAcceleration;
		// �Ƕȱ任�ٶ�
		sys::Vector _angleAcceleration;
		// ���ű任�ٶ�
		sys::Vector _scaleAcceleration;
		// ɫ���ٶ�
		sys::Color4F _colorAcceleration;
		// ����
		float _liftTime;
	};
}