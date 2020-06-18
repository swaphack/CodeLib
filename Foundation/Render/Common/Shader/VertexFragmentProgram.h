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
		*	����ļ� vpath ���㣬 fpathƬԪ
		*/
		bool loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath);
	};
}