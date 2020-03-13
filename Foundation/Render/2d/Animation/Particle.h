#pragma once

#include "macros.h"

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
		void setSpeedAcceleration(float x, float y, float z);
		// 获取加速度
		math::Vector3 getSpeedAccelertaion();
		// 设置角度变换速度
		void setAngleAcceleration(float x, float y, float z);
		// 获取角度变换速度
		math::Vector3 getAngleAcceleration();
		// 设置缩放变换速度
		void setScaleAcceleration(float x, float y, float z);
		// 获取缩放变换速度
		math::Vector3 getScaleAcceleration();
		// 设置色彩渐变速度
		void setColorAcceleration(float red, float green, float blue, float alpha);
		// 获取色彩渐变速度
		sys::Color4F getColorAcceleration();
		// 设置寿命
		void setLifeTime(float time);
		// 获取寿命
		float getLifeTime();
	protected:
		// 加速度
		math::Vector3 _speedAcceleration;
		// 角度变换速度
		math::Vector3 _angleAcceleration;
		// 缩放变换速度
		math::Vector3 _scaleAcceleration;
		// 色变速度
		sys::Color4F _colorAcceleration;
		// 寿命
		float _lifeTime;
	};
}