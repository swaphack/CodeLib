#pragma once

#include "macros.h"
#include "Particle.h"

namespace render
{
	// ����
	class ParticleNode : public ColorNode, public ParticleProtocol
	{
	public:
		ParticleNode();
		virtual ~ParticleNode();
	public:
		virtual void draw();
		// ����
		virtual void update(float interval);
	protected:
		virtual void initSelf();
	private:
		// ��ʼ��ɫ
		sys::Color4F _colorInit;
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