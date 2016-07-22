#pragma once

#include "macros.h"
#include "Particle.h"

namespace render
{
	// 粒子
	class ParticleNode : public ColorNode, public ParticleProtocol
	{
	public:
		ParticleNode();
		virtual ~ParticleNode();
	public:
		virtual void draw();
		// 更新
		virtual void update(float interval);
	protected:
		virtual void initSelf();
	private:
		// 初始颜色
		sys::Color4F _colorInit;
		// 纹理坐标
		TextureRect _texRect;
	};

	// 粒子系统
	class CtrlParticleSystem : public Animation
	{
	public:
		CtrlParticleSystem();
		virtual ~CtrlParticleSystem();
	public:
		virtual bool init();
		// 设置粒子个数
		void setCount(uint count);
		// 获取粒子个数
		uint getCount();
		// 粒子播放结束后处理 override
		virtual void onParticleEndHandler();
		// 创建粒子 override
		virtual ParticleNode* createParticle();
	protected:
		virtual void updateSelf(float interval);
	private:
		uint _particleCount;
	};
}