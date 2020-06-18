#pragma once

#include "Common/Node/Node.h"
#include "ParticleProtocol.h"

namespace render
{
	class Scheduler;

	/**
	*	���ӽڵ�
	*/
	class PariticleNode :
		public Node,
		public ParticleProtocol
	{
	public:
		PariticleNode();
		virtual ~PariticleNode();
	public:
		virtual bool init();

		float getDelta() const;
	protected:
		virtual void onPariticleChange();
	
		void updatePariticle(float dt);
	protected:
		// ����ʱ��
		virtual void updateTime(float dt);
		// �����ı�
		virtual void updateParticleParameter();
	private:
		Scheduler* _scheduler = nullptr;

		float _delta = 0;
	};
}