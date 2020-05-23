#include "Utility.h"

using namespace render;

std::string Utility::texture3dVertexPath = "Shader/texture3d_vertex.glsl";
std::string Utility::texture3dFragmentPath = "Shader/texture3d_fragment.glsl";

void Utility::loadShader(render::Materials* mats, const std::string& vpath, const std::string& fpath)
{
	if (mats == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vpath, fpath);
	pProgram->link();

	for (auto item : mats->getMaterials())
	{
		item.second->setShaderProgram(pProgram);
	}

}

void Utility::initShaderAttrib(render::Materials* mats)
{
	if (mats == nullptr)
	{
		return;
	}

	for (auto item : mats->getMaterials())
	{
		item.second->addUniform(VertexUniformType::PROJECT_MATRIX, "projectMatrix");
		item.second->addUniform(VertexUniformType::VIEW_MATRIX, "viewMatrix");
		item.second->addUniform(VertexUniformType::MODEL_VIEW, "modelMatrix");

		item.second->addUniform(VertexUniformType::AMBIENT_TEXTURE, "texSampler0");
		item.second->addUniform(VertexUniformType::DIFFUSE_TEXTURE, "texSampler1");

		item.second->addAttrib(VertexAttribType::POSITION, "vPosition");
		item.second->addAttrib(VertexAttribType::COLOR, "vColor");
		item.second->addAttrib(VertexAttribType::UV, "vUV");
	}
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

void Utility::updateNodeShader(render::DrawNode* node)
{
	loadShader(node->getMaterials(), texture3dVertexPath, texture3dFragmentPath);
	initShaderAttrib(node->getMaterials());
}
