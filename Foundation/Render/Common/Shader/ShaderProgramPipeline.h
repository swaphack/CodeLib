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
		*	���ñ������
		*/
		void setProgramPipelineID(uint32_t id);
		/**
		*	���Ա��
		*/
		uint32_t getProgramPipelineID() const;
	public:
		/**
		*	��
		*/
		void bind();
		/**
		*	�Ƿ����
		*/
		bool isValid() const;
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
		void initProgramPipeline();
		void releaseProgramPopeline();
	private:
		uint32_t _programPipelineID = 0;
	};
}