#include "VertexShader.h"

using namespace render;

VertexShader::VertexShader()
{
	this->setShaderType(ShaderType::VERTEX_SHADER);
	this->initShader();
}

VertexShader::~VertexShader()
{

}