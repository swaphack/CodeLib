#pragma once

#include "system.h"
#include "Common/DrawNode/DrawNode.h"
#include "Particle.h"
#include "CtrlAnimation.h"
#include "Common/struct/texture_common.h"

namespace render
{
	// ����
	class ParticleNode : public DrawNode, public ParticleProtocol
	{
	public:
		ParticleNode();
		virtual ~ParticleNode();
	protected:
		virtual void drawing();
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
	class CtrlParticleSystem : public CtrlAnimation // ��������
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