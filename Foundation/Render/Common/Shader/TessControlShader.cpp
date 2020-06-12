#include "TessControlShader.h"

render::TessControlShader::TessControlShader()
{
	this->setShaderType(ShaderType::TESS_CONTROL_SHADER);
	this->initShader();
}

render::TessControlShader::~TessControlShader()
{

}