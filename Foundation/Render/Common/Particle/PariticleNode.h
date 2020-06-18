#pragma once

#include "Common/Node/Node.h"
#include "ParticleProtocol.h"

namespace render
{
	class Scheduler;

	/**
	*	粒子节点
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
		// 更新时间
		virtual void updateTime(float dt);
		// 参数改变
		virtual void updateParticleParameter();
	private:
		Scheduler* _scheduler = nullptr;

		float _delta = 0;
	};
}