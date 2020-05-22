#include "ShaderProgramPipeline.h"
#include "Graphic/import.h"
#include "ShaderProgram.h"

using namespace render;

render::ShaderProgramPipeline::ShaderProgramPipeline()
{
	this->initProgramPipeline();
}

render::ShaderProgramPipeline::~ShaderProgramPipeline()
{
	this->releaseProgramPopeline();
}

void render::ShaderProgramPipeline::setProgramPipelineID(uint32_t id)
{
	_programPipelineID = id;
}

uint32_t render::ShaderProgramPipeline::getProgramPipelineID() const
{
	return _programPipelineID;
}

void render::ShaderProgramPipeline::bind()
{
	GLProgramPipelines::bindProgramPipeline(getProgramPipelineID());
}

bool render::ShaderProgramPipeline::isValid() const
{
	return GLProgramPipelines::isProgramPipeline(getProgramPipelineID());
}

void render::ShaderProgramPipeline::validate()
{
	GLProgramPipelines::validateProgramPipeline(getProgramPipelineID());
}

void render::ShaderProgramPipeline::getValue(ProgramPipelineParameter pname, int* value)
{
	GLProgramPipelines::getProgramPipeline(getProgramPipelineID(), pname, value);
}

void render::ShaderProgramPipeline::active()
{
	GLProgramPipelines::activeShaderProgram(getProgramPipelineID(), getProgramID());
}

void render::ShaderProgramPipeline::initProgramPipeline()
{
	GLProgramPipelines::createProgramPipelines(1, &_programPipelineID);
}

void render::ShaderProgramPipeline::releaseProgramPopeline()
{
	GLProgramPipelines::deleteProgramPipeline(1, &_programPipelineID);
}
