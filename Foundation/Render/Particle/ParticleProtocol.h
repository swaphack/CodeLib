#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	// 粒子
	class ParticleProtocol
	{
	public:
		ParticleProtocol();
		virtual ~ParticleProtocol();
	public:
		// 设置加速度
		void setSpeedAcceleration(float x, float y, float z = 0);
		// 获取加速度
		const math::Vector3& getSpeedAccelertaion() const;
		// 设置角度变换速度
		void setAngleAcceleration(float x, float y, float z = 0);
		// 获取角度变换速度
		const math::Vector3& getAngleAcceleration() const;
		// 设置缩放变换速度
		void setScaleAcceleration(float x, float y, float z = 0);
		// 获取缩放变换速度
		const math::Vector3& getScaleAcceleration() const;
		// 设置色彩渐变速度
		void setColorAcceleration(float red, float green, float blue, float alpha = 1);
		// 获取色彩渐变速度
		const phy::Color4F& getColorAcceleration() const;
		// 设置寿命
		void setLifeTime(float time);
		// 获取寿命
		float getLifeTime();
		// 设置粒子数量
		void setParticleCount(int count);
		// 获取粒子数量
		int getParticleCount() const;
	protected:
		virtual void onPariticleChange();
	protected:
		// 加速度
		math::Vector3 _speedAcceleration;
		// 角度变换速度
		math::Vector3 _angleAcceleration;
		// 缩放变换速度
		math::Vector3 _scaleAcceleration;
		// 色变速度
		phy::Color4F _colorAcceleration;
		// 寿命
		float _lifeTime = 0;
		// 粒子数量
		int _particleCount = 1;
	};
}