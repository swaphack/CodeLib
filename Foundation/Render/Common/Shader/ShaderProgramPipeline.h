#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	管线
	*/
	class ShaderProgramPipeline : public ShaderVariable
	{
	public:
		ShaderProgramPipeline();
		virtual ~ShaderProgramPipeline();
	public:
		/**
		*	绑定
		*/
		void bind();
		/**
		*	是否可用
		*/
		bool isValidate();
		/**
		*	验证是否可用
		*/
		void validate();
		/**
		*	获取相关值
		*/
		void getValue(ProgramPipelineParameter pname, int* value);
		/**
		*	激活
		*/
		void active();
	protected:
		void initPipeline();
		void releasePopeline();
	};
}