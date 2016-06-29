#pragma once

#include "../macros.h"

namespace render
{
#define SPHERE_HORIZONTAL_COUNT 20
#define SPHERE_VERTICAL_COUNT 20

	// 3d模型基础，球
	class Sphere : public CtrlModel
	{
	public:
		Sphere();
		virtual ~Sphere();
	public:
		virtual void draw();

		// 设置球半径
		void setRadius(float radius);
		// 获取球半径
		float getRadius();
	protected:
		virtual void initSelf();
	private:
		// 球半径
		float _radius;
	};
}