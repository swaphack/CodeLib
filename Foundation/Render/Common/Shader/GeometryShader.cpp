#include "GeometryShader.h"

render::GeometryShader::GeometryShader()
{
	this->setShaderType(ShaderType::GEOMETRY_SHADER);
	this->initShader();
}

render::GeometryShader::~GeometryShader()
{

}