#pragma once

#include "system.h"
#include "Common/DrawNode/DrawNode.h"
#include "ParticleProtocol.h"
#include "CtrlAnimation.h"
#include "Common/struct/vertex_common.h"

namespace render
{
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
	protected:
		virtual void updateSelf(float interval);
	private:
		uint32_t _particleCount;
	};
}