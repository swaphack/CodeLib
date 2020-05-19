#include "Utility.h"

using namespace render;

std::string Utility::texture3dVertexPath = "Shader/texture3d_vertex.glsl";
std::string Utility::texture3dFragmentPath = "Shader/texture3d_fragment.glsl";

void Utility::loadShader(render::Material* mat, const std::string& vpath, const std::string& fpath)
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

void Utility::initShaderAttrib(render::Material* mat)
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

void Utility::initProgramAttrib(render::ShaderProgram* program)
{
	if (program == nullptr)
	{
		return;
	}

	program->bindAttrib((uint32_t)VertexAttribType::POSITION, "vPosition");
	program->bindAttrib((uint32_t)VertexAttribType::COLOR, "vColor");
	program->bindAttrib((uint32_t)VertexAttribType::UV, "vUV");

	GLDebug::showError();
}

void Utility::runRotateAction(render::Node* node)
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

void Utility::updateNodeShader(render::DrawNode* node, bool autoRotate)
{
	loadShader(node->getMaterial(), texture3dVertexPath, texture3dFragmentPath);
	initShaderAttrib(node->getMaterial());
	if (autoRotate)
	{
		runRotateAction(node);
	}
}
