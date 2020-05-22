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
		*	设置变量编号
		*/
		void setProgramPipelineID(uint32_t id);
		/**
		*	属性编号
		*/
		uint32_t getProgramPipelineID() const;
	public:
		/**
		*	绑定
		*/
		void bind();
		/**
		*	是否可用
		*/
		bool isValid() const;
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
		void initProgramPipeline();
		void releaseProgramPopeline();
	private:
		uint32_t _programPipelineID = 0;
	};
}