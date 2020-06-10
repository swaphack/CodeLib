#include "Utility.h"

using namespace render;

std::string Utility::texture3dVertexPath = "Shader/texture3d.vs";
std::string Utility::texture3dFragmentPath = "Shader/texture3d.fs";

void Utility::loadShader(render::Materials* mats, const std::string& vpath, const std::string& fpath)
{
	if (mats == nullptr)
	{
		return;
	}
	ShaderProgram* pProgram = CREATE_OBJECT(ShaderProgram);
	pProgram->loadVertexAndFragmentShader(vpath, fpath);
	pProgram->bindFragDataLocation(0, "color");
	pProgram->link();


	for (auto item : mats->getMaterials())
	{
		item.second->setShaderProgram(pProgram);
	}

	initShaderAttrib(mats);

}

void Utility::initShaderAttrib(render::Materials* mats)
{
	if (mats == nullptr)
	{
		return;
	}

	for (auto item : mats->getMaterials())
	{
		item.second->addUniform(UniformType::PROJECT_MATRIX, "projectMatrix");
		item.second->addUniform(UniformType::VIEW_MATRIX, "viewMatrix");
		item.second->addUniform(UniformType::MODEL_VIEW, "modelMatrix");

		item.second->addUniform(UniformType::TEXTURE0, "texSampler0");
		item.second->addUniform(UniformType::TEXTURE1, "texSampler1");

		item.second->addUniform(UniformType::LIGHT_COLOR, "lightColor");
		item.second->addUniform(UniformType::LIGHT_POSITION, "lightPos");
		item.second->addUniform(UniformType::VIEW_POSITION, "viewPos");

		item.second->addUniform(UniformType::MATERIAL_AMBIENT, "material.ambient");
		item.second->addUniform(UniformType::MATERIAL_DIFFUSE, "material.diffuse");
		item.second->addUniform(UniformType::MATERIAL_SPECULAR, "material.specular");
		item.second->addUniform(UniformType::MATERIAL_SHININESS, "material.shininess");

		item.second->addVertexData(VertexDataType::POSITION, "vPosition");
		item.second->addVertexData(VertexDataType::COLOR, "vColor");
		item.second->addVertexData(VertexDataType::UV, "vUV");
		item.second->addVertexData(VertexDataType::NORMAL, "vNormal");
	}
}

void Utility::bindProgramAttrib(render::ShaderProgram* program)
{
	if (program == nullptr)
	{
		return;
	}

	program->bindAttrib((uint32_t)VertexDataType::POSITION, "vPosition");
	program->bindAttrib((uint32_t)VertexDataType::COLOR, "vColor");
	program->bindAttrib((uint32_t)VertexDataType::UV, "vUV");

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
}
