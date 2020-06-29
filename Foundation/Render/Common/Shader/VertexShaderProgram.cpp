#include "VertexShaderProgram.h"

render::VertexShaderProgram::VertexShaderProgram()
{

}

render::VertexShaderProgram::~VertexShaderProgram()
{

}

bool render::VertexShaderProgram::loadVertexShader(const std::string& vpath)
{
	if (!this->loadShaderFromFile(ShaderType::VERTEX_SHADER, vpath))
	{
		return false;
	}

	return true;
}

