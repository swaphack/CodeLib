#pragma once

#include "Common/Node/Node.h"
#include "ParticleProtocol.h"
#include "Common/Action/SchedulerProtocol.h"

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
		/** 
		*	重置运行时间
		*/
		void resetPassedTime();
		/**
		*	获取运行时间
		*/ 
		float getPassedTime() const;
	protected:
		/**
		*	粒子配置改变时
		*/
		virtual void onPariticleChange();
		/**
		*	更新粒子
		*/
		void updatePariticle(float dt);
	protected:
		// 更新时间
		virtual void update(float dt);
		// 参数改变
		virtual void updateParticleParameter();
	protected:
		// 运行时间
		float _passedTime = 0;

		float _deltaTime = 0;
	};
}