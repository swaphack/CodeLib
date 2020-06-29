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
		*	����ļ� vpath ���㣬 fpathƬԪ
		*/
		bool loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath);
	};
}