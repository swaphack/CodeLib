#pragma once

#include "../../Common/common.h"

namespace render
{
	// 3d模型基础，球
	class Sphere : public Node
	{
	public:
		Sphere();
		virtual ~Sphere();
	public:
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