#pragma once

#include "system.h"
#include "mathlib.h"

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
		void setSpeedAcceleration(float x, float y, float z = 0);
		// ��ȡ���ٶ�
		const math::Vector3& getSpeedAccelertaion() const;
		// ���ýǶȱ任�ٶ�
		void setAngleAcceleration(float x, float y, float z = 0);
		// ��ȡ�Ƕȱ任�ٶ�
		const math::Vector3& getAngleAcceleration() const;
		// �������ű任�ٶ�
		void setScaleAcceleration(float x, float y, float z = 0);
		// ��ȡ���ű任�ٶ�
		const math::Vector3& getScaleAcceleration() const;
		// ����ɫ�ʽ����ٶ�
		void setColorAcceleration(float red, float green, float blue, float alpha = 1);
		// ��ȡɫ�ʽ����ٶ�
		const phy::Color4F& getColorAcceleration() const;
		// ��������
		void setLifeTime(float time);
		// ��ȡ����
		float getLifeTime();
		// ������������
		void setParticleCount(int count);
		// ��ȡ��������
		int getParticleCount() const;
	protected:
		virtual void onPariticleChange();
	protected:
		// ���ٶ�
		math::Vector3 _speedAcceleration;
		// �Ƕȱ任�ٶ�
		math::Vector3 _angleAcceleration;
		// ���ű任�ٶ�
		math::Vector3 _scaleAcceleration;
		// ɫ���ٶ�
		phy::Color4F _colorAcceleration;
		// ����
		float _lifeTime = 0;
		// ��������
		int _particleCount = 1;
	};
}