#pragma once


#include "Light.h"

namespace render
{
	/**
	*	点光源
	*/
	class PointLight : public Light
	{
	public:
		PointLight();
		virtual ~PointLight();
	public:
		virtual void draw();
	public:

		// 常量衰减，与距离无关
		void setConstantAttenuation(float value);
		float getConstantAttenuation();

		// 按距离线性衰减
		void setLinearAttenuation(float value);
		float getLinearAttenuation();

		// 按距离二次函数衰减
		void setQuadraticAttenuation(float value);
		float getQuadraticAttenuation();
	protected:
		// 常量衰减，与距离无关
		float _constantAttenuation;
		// 按距离线性衰减
		float _linearAttenuation;
		// 按距离二次函数衰减
		float _quadraticAttenuation;
	};
}