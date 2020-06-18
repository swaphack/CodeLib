#pragma once

#include "ShaderProgram.h"

namespace render
{
	class VertexFragmentProgram : public ShaderProgram
	{
	public:
		VertexFragmentProgram();
		virtual ~VertexFragmentProgram();
	public:
		/**
		*	添加文件 vpath 顶点， fpath片元
		*/
		bool loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath);
	};
}