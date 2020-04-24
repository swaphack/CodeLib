#pragma once

#include "macros.h"

namespace render
{
	/**
	*	可编程管道
	*/
	class GLProgramPipelines
	{
	public:
		static void activeShaderProgram(uint32_t pipeline, uint32_t program);
		static void bindProgramPipeline(uint32_t pipeline);
		static void createProgramPipelines(int n, uint32_t* pipelines);
		static void deleteProgramPipeline(int n, uint32_t* pipelines);

		static void genProgramPipelines(int n, uint32_t* pipelines);
		static bool isProgramPipeline(uint32_t pipeline);
		static void validateProgramPipeline(uint32_t pipeline);

		static void getProgramPipeline(uint32_t pipeline, ProgramPipelineParameter name, int* value);

		static void showProgramPipelineStatus(uint32_t pipeline);
	};
}