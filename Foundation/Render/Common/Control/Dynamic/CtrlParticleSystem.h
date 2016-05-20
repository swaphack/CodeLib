#pragma once

#include "macros.h"

namespace render
{
	// ����
	class ParticleNode : public ColorNode, public sys::ITimer
	{
	public:
		ParticleNode();
		virtual ~ParticleNode();
	public:
		virtual void draw();
		// ���ü��ٶ�
		void setSpeedAcceleration(float x, float y, float z);
		// ��ȡ���ٶ�
		sys::Vector getSpeedAccelertaion();
		// ����ɫ�ʽ����ٶ�
		void setColorAcceleration(float red, float green, float blue, float alpha);
		// ��ȡɫ�ʽ����ٶ�
		sys::Color4F getColorAcceleration();
		// ��������
		void setLifeTime(float time);
		// ��ȡ����
		float getLifeTime();
		// ����
		virtual void update(float interval);
	protected:
		virtual void initSelf();
	private:
		sys::Color4F _colorInit;
		// ���ٶ�
		sys::Vector _speedAcceleration;
		// ɫ���ٶ�
		sys::Color4F _colorAcceleration;
		// ����
		float _liftTime;
		// ��������
		TextureRect _texRect;
	};

	// ����ϵͳ
	class CtrlParticleSystem : public Animation
	{
	public:
		CtrlParticleSystem();
		virtual ~CtrlParticleSystem();
	public:
		virtual bool init();
		// �������Ӹ���
		void setCount(uint count);
		// ��ȡ���Ӹ���
		uint getCount();
		// ���Ӳ��Ž������� override
		virtual void onParticleEndHandler();
		// �������� override
		virtual ParticleNode* createParticle();
	protected:
		virtual void updateSelf(float interval);
	private:
		uint _particleCount;
	};
}