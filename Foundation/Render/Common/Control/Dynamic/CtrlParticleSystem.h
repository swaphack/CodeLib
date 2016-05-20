#pragma once

#include "macros.h"

namespace render
{
	// 粒子
	class ParticleNode : public ColorNode, public sys::ITimer
	{
	public:
		ParticleNode();
		virtual ~ParticleNode();
	public:
		virtual void draw();
		// 设置加速度
		void setSpeedAcceleration(float x, float y, float z);
		// 获取加速度
		sys::Vector getSpeedAccelertaion();
		// 设置色彩渐变速度
		void setColorAcceleration(float red, float green, float blue, float alpha);
		// 获取色彩渐变速度
		sys::Color4F getColorAcceleration();
		// 设置寿命
		void setLifeTime(float time);
		// 获取寿命
		float getLifeTime();
		// 更新
		virtual void update(float interval);
	protected:
		virtual void initSelf();
	private:
		sys::Color4F _colorInit;
		// 加速度
		sys::Vector _speedAcceleration;
		// 色变速度
		sys::Color4F _colorAcceleration;
		// 寿命
		float _liftTime;
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