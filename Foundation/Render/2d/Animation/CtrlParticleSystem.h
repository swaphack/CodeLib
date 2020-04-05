#pragma once

#include "system.h"
#include "Common/Node/ColorNode.h"
#include "Particle.h"
#include "Common/Node/Animation.h"

namespace render
{
	// ����
	class ParticleNode : public ColorNode, public ParticleProtocol
	{
	public:
		ParticleNode();
		virtual ~ParticleNode();
	protected:
		virtual void drawSample();
	public:
		// ����
		virtual void update(float interval);
	protected:
	private:
		// ��ʼ��ɫ
		sys::Color4F _colorInit;
		// ��������
		TextureRectVertex _texRect;
	};

	// ����ϵͳ
	class CtrlParticleSystem : public Animation // ��������
	{
	public:
		CtrlParticleSystem();
		virtual ~CtrlParticleSystem();
	public:
		virtual bool init();
		// �������Ӹ���
		void setCount(uint32_t count);
		// ��ȡ���Ӹ���
		uint32_t getCount();
		// ���Ӳ��Ž������� override
		virtual void onParticleEndHandler();
		// �������� override
		virtual ParticleNode* createParticle();
	protected:
		virtual void updateSelf(float interval);
	private:
		uint32_t _particleCount;
	};
}