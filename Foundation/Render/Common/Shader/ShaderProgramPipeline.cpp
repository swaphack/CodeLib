#include "ShaderProgramPipeline.h"
#include "Graphic/import.h"
#include "ShaderProgram.h"

using namespace render;

render::ShaderProgramPipeline::ShaderProgramPipeline()
{
	this->initPipeline();
}

render::ShaderProgramPipeline::~ShaderProgramPipeline()
{
	this->releasePopeline();
}

void render::ShaderProgramPipeline::bind()
{
	GLProgramPipelines::bindProgramPipeline(_varID);
}

bool render::ShaderProgramPipeline::isValidate()
{
	return GLProgramPipelines::isProgramPipeline(_varID);
}

void render::ShaderProgramPipeline::validate()
{
	GLProgramPipelines::validateProgramPipeline(_varID);
}

void render::ShaderProgramPipeline::getValue(ProgramPipelineParameter pname, int* value)
{
	GLProgramPipelines::getProgramPipeline(_varID, pname, value);
}

void render::ShaderProgramPipeline::active()
{
	GLProgramPipelines::activeShaderProgram(_varID, getProgramID());
}

void render::ShaderProgramPipeline::initPipeline()
{
	GLProgramPipelines::createProgramPipelines(1, &_varID);
}

void render::ShaderProgramPipeline::releasePopeline()
{
	GLProgramPipelines::deleteProgramPipeline(1, &_varID);
}
