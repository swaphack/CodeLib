#pragma once

#include "system.h"
#include "Common/DrawNode/DrawNode.h"
#include "ParticleProtocol.h"
#include "CtrlAnimation.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	// 粒子系统
	class CtrlParticleSystem : public CtrlAnimation // 还有问题
	{
	public:
		CtrlParticleSystem();
		virtual ~CtrlParticleSystem();
	public:
		virtual bool init();
		// 设置粒子个数
		void setCount(uint32_t count);
		// 获取粒子个数
		uint32_t getCount();
		// 粒子播放结束后处理 override
		virtual void onParticleEndHandler();
	protected:
		virtual void updateSelf(float interval);
	private:
		uint32_t _particleCount;
	};
}