#pragma once
#include "Shader.h"

namespace render
{
	class ComputeShader : public Shader
	{
	public:
		ComputeShader();
		virtual ~ComputeShader();
	};
}