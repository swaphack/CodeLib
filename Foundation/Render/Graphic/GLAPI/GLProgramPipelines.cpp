#include "GLProgramPipelines.h"

using namespace render;

void GLProgramPipelines::activeShaderProgram(uint32_t pipeline, uint32_t program)
{
	glActiveShaderProgram(pipeline, program);
}

void GLProgramPipelines::bindProgramPipeline(uint32_t pipeline)
{
	glBindProgramPipeline(pipeline);
}

void GLProgramPipelines::createProgramPipelines(int n, uint32_t* pipelines)
{
	glCreateProgramPipelines(n, pipelines);
}

void GLProgramPipelines::deleteProgramPipeline(int n, uint32_t* pipelines)
{
	glDeleteProgramPipelines(n, pipelines);
}

void GLProgramPipelines::genProgramPipelines(int n, uint32_t* pipelines)
{
	glGenProgramPipelines(n, pipelines);
}

void GLProgramPipelines::showProgramPipelineStatus(uint32_t pipeline)
{
	GLsizei bufferSize = 0;
	glGetProgramPipelineiv(pipeline, GL_INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		glGetProgramPipelineInfoLog(pipeline, bufferSize, NULL, buffer);
		PRINT("%s", buffer);
		delete[] buffer;
	}
}

bool GLProgramPipelines::isProgramPipeline(uint32_t pipeline)
{
	return glIsProgramPipeline(pipeline) == 1;
}

void GLProgramPipelines::validateProgramPipeline(uint32_t pipeline)
{
	glValidateProgramPipeline(pipeline);
}

void GLProgramPipelines::getProgramPipeline(uint32_t pipeline, ProgramPipelineParameter name, int* value)
{
	glGetProgramPipelineiv(pipeline, (GLenum)name, value);
}
