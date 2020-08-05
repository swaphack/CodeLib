#pragma once

#include "Light.h"

namespace render
{
	/**
	*	ֱ���
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
		// ����
		const float* getDirection();

		void setDirection(const math::Vector3& direction);
		void setDirection(float x, float y, float z);
	protected:
		// ����
		float _lightDirection[3];
	};
}