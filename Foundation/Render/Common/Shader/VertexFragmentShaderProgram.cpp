#include "VertexFragmentShaderProgram.h"


render::VertexFragmentShaderProgram::VertexFragmentShaderProgram()
{

}

render::VertexFragmentShaderProgram::~VertexFragmentShaderProgram()
{

}

bool render::VertexFragmentShaderProgram::loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath)
{
	if (!this->loadShaderFromFile(ShaderType::VERTEX_SHADER, vpath))
	{
		return false;
	}
	if (!this->loadShaderFromFile(ShaderType::FRAGMENT_SHADER, fpath))
	{
		return false;
	}

	return true;
}

