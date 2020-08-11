#pragma once

#include "Common/Node/Node.h"
#include "ParticleProtocol.h"
#include "Common/Action/SchedulerProtocol.h"

namespace render
{
	class Scheduler;

	/**
	*	���ӽڵ�
	*/
	class PariticleNode :
		public Node,
		public ParticleProtocol,
		public SchedulerProtocol
	{
	public:
		PariticleNode();
		virtual ~PariticleNode();
	public:
		virtual bool init();
		/** 
		*	��������ʱ��
		*/
		void resetPassedTime();
		/**
		*	��ȡ����ʱ��
		*/ 
		float getPassedTime() const;
	protected:
		/**
		*	��Ӷ�ʱ��
		*/
		virtual void registerScheduler();
		/**
		*	�Ƴ���ʱ��
		*/
		virtual void unregisterScheduler();
		/**
		*	�������øı�ʱ
		*/
		virtual void onPariticleChange();
		/**
		*	��������
		*/
		void updatePariticle(float dt);
	protected:
		// ����ʱ��
		virtual void update(float dt);
		// �����ı�
		virtual void updateParticleParameter();
	protected:
		// ����ʱ��
		float _passedTime = 0;

		float _deltaTime = 0;
	};
}