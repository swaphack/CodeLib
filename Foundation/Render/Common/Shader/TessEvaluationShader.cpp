#include "TessEvaluationShader.h"

render::TessEvaluationShader::TessEvaluationShader()
{
	this->setShaderType(ShaderType::TESS_EVALUATION_SHADER);
	this->initShader();
}

render::TessEvaluationShader::~TessEvaluationShader()
{

}