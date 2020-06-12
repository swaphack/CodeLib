#include "ComputeShader.h"

render::ComputeShader::ComputeShader()
{
	this->setShaderType(ShaderType::COMPUTE_SHADER);
	this->initShader();
}

render::ComputeShader::~ComputeShader()
{

}