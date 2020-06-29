#pragma once

#include "ShaderProgram.h"

namespace render
{
	class VertexFragmentShaderProgram : public ShaderProgram
	{
	public:
		VertexFragmentShaderProgram();
		virtual ~VertexFragmentShaderProgram();
	public:
		/**
		*	添加文件 vpath 顶点， fpath片元
		*/
		bool loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath);
	};
}