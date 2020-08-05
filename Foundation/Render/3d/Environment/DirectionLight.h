#pragma once

#include "Light.h"

namespace render
{
	/**
	*	直射光
	*/
	class DirectionLight : public Light
	{
	public:
		DirectionLight();
		virtual ~DirectionLight();
	public:
		virtual void draw();

		virtual bool init();
	public:
		// 朝向
		const float* getDirection();

		void setDirection(const math::Vector3& direction);
		void setDirection(float x, float y, float z);
	protected:
		// 朝向
		float _lightDirection[3];
	};
}