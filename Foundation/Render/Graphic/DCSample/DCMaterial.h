#pragma once

#include "macros.h"

namespace render
{
	/**
	*	材质属性
	*/
	class DCMaterial : public DrawCommand
	{
	public:
		// 环境光
		float Ambient[4];
		// 漫射光
		float Diffuse[4];
		// 反射光
		float Specular[4];
		// 镜面指数
		float Shiness = 0;
		// 辐射光颜色
		float Emission[4];
	public:
		DCMaterial();
		virtual ~DCMaterial();
	public:
		virtual void draw();
	public:
		static DCMaterial* create(float* ambient, float* diffuse, float* specular, float shiness, float* emission);
	};
}