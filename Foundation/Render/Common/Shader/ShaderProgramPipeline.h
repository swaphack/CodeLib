#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	����
	*/
	class ShaderProgramPipeline : public ShaderVariable
	{
	public:
		ShaderProgramPipeline();
		virtual ~ShaderProgramPipeline();
	public:
		/**
		*	��
		*/
		void bind();
		/**
		*	�Ƿ����
		*/
		bool isValidate();
		/**
		*	��֤�Ƿ����
		*/
		void validate();
		/**
		*	��ȡ���ֵ
		*/
		void getValue(ProgramPipelineParameter pname, int* value);
		/**
		*	����
		*/
		void active();
	protected:
		void initPipeline();
		void releasePopeline();
	};
}