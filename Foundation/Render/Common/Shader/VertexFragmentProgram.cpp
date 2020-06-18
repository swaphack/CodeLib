#include "VertexFragmentProgram.h"


render::VertexFragmentProgram::VertexFragmentProgram()
{

}

render::VertexFragmentProgram::~VertexFragmentProgram()
{

}

bool render::VertexFragmentProgram::loadVertexAndFragmentShader(const std::string& vpath, const std::string& fpath)
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

