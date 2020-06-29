#pragma once

#include "ShaderProgram.h"

namespace render
{
	class VertexShaderProgram : public ShaderProgram
	{
	public:
		VertexShaderProgram();
		virtual ~VertexShaderProgram();
	public:
		/**
		*	����ļ� vpath ����
		*/
		bool loadVertexShader(const std::string& vpath);
	};
}
