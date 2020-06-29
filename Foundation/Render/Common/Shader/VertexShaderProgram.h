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
		*	添加文件 vpath 顶点
		*/
		bool loadVertexShader(const std::string& vpath);
	};
}
