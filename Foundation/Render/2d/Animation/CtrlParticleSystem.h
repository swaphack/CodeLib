#pragma once

#include "system.h"
#include "Common/Node/ColorNode.h"
#include "Particle.h"
#include "Common/Node/Animation.h"

namespace render
{
	// 粒子
	class ParticleNode : public ColorNode, public ParticleProtocol
	{
	public:
		ParticleNode();
		virtual ~ParticleNode();
	protected:
		virtual void drawSample();
	public:
		// 更新
		virtual void update(float interval);
	protected:
	private:
		// 初始颜色
		sys::Color4F _colorInit;
		// 纹理坐标
		TextureRectVertex _texRect;
	};

	// 粒子系统
	class CtrlParticleSystem : public Animation // 还有问题
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
		// 创建粒子 override
		virtual ParticleNode* createParticle();
	protected:
		virtual void updateSelf(float interval);
	private:
		uint32_t _particleCount;
	};
}