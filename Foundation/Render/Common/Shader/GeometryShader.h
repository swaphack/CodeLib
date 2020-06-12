#pragma once

#include "Shader.h"

namespace render
{
	/**
	*	几何着色器
	*/
	class GeometryShader : public Shader
	{
	public:
		GeometryShader();
		virtual ~GeometryShader();
	};
}