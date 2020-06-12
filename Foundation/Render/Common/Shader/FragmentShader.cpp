#include "FragmentShader.h"

using namespace render;

FragmentShader::FragmentShader()
{
	this->setShaderType(ShaderType::FRAGMENT_SHADER);
	this->initShader();
}

FragmentShader::~FragmentShader()
{

}