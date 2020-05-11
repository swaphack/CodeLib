#include "ShaderUtility.h"

using namespace render;

static std::string texture3dVertexPath = "Shader/texture3d_vertex.glsl";
static std::string texture3dFragmentPath = "Shader/texture3d_fragment.glsl";

void ShaderUtility::loadShader(render::Material* mat, const std::string& vpath, const std::string& fpath)
{
	if (mat == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vpath, fpath);
	pProgram->link();

	mat->setShaderProgram(pProgram);
}

void ShaderUtility::initShaderAttrib(render::Material* mat)
{
	if (mat == nullptr)
	{
		return;
	}

	mat->addUniform(VertexUniformType::PROJECT_MATRIX, "projectMatrix");
	mat->addUniform(VertexUniformType::VIEW_MATRIX, "viewMatrix");
	mat->addUniform(VertexUniformType::MODEL_VIEW, "modelMatrix");

	mat->addUniform(VertexUniformType::AMBIENT_TEXTURE, "texSampler0");
	mat->addUniform(VertexUniformType::DIFFUSE_TEXTURE, "texSampler1");

	mat->addAttrib(VertexAttribType::POSITION, "vPosition");
	mat->addAttrib(VertexAttribType::COLOR, "vColor");
	mat->addAttrib(VertexAttribType::UV, "vUV");
}

void ShaderUtility::runRotateAction(render::Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	RotateByAction* pRotateByAction = CREATE_ACTION(RotateByAction);
	pRotateByAction->setRotation(180, 180, 0);
	pRotateByAction->setDuration(10);

	RepeateForeverAction* pRepeateAction = CREATE_ACTION(RepeateForeverAction);
	pRepeateAction->setAction(pRotateByAction);

	node->getActionProxy()->runAction(pRepeateAction);
}

void ShaderUtility::updateNodeShader(render::CtrlFrame* node)
{
	loadShader(node->getMaterial(), texture3dVertexPath, texture3dFragmentPath);
	initShaderAttrib(node->getMaterial());
	runRotateAction(node);
}

void ShaderUtility::updateNodeShader(render::Model* node)
{
	loadShader(node->getMaterial(), texture3dVertexPath, texture3dFragmentPath);
	initShaderAttrib(node->getMaterial());
	runRotateAction(node);
}
